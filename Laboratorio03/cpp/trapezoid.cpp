#include <condition_variable>
#include <functional>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

class Function {
public:
    virtual double eval(double x) const = 0;
    virtual ~Function() = default;
};

class Quadratic : public Function {
public:
    double eval(double x) const override {
        return 2.0 * x * x + 3.0 * x + 0.5;
    }
};

class ThreadPool {
public:
    explicit ThreadPool(size_t n) : stop(false) {
        for (size_t i = 0; i < n; ++i) {
            workers.emplace_back([this] { workerLoop(); });
        }
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();
        for (auto &w : workers) {
            if (w.joinable()) w.join();
        }
    }

    void enqueue(std::function<void()> task) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            tasks.push(std::move(task));
        }
        cv.notify_one();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop;

    void workerLoop() {
        for (;;) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this] { return stop || !tasks.empty(); });
                if (stop && tasks.empty()) return;
                task = std::move(tasks.front());
                tasks.pop();
            }
            task();
        }
    }
};

double integrate(const Function &f, double a, double b, int n, ThreadPool &pool) {
    double h = (b - a) / n;

    unsigned workers = std::thread::hardware_concurrency();
    if (workers == 0) workers = 4;
    if (static_cast<unsigned>(n) < workers) workers = static_cast<unsigned>(n);

    // Memoria dinamica para las sumas parciales de cada hilo.
    double *partial = new double[workers]();
    int remaining = static_cast<int>(workers);
    std::mutex doneMtx;
    std::condition_variable doneCv;

    int chunk = n / static_cast<int>(workers);
    int rem = n % static_cast<int>(workers);
    int start = 0;

    for (unsigned w = 0; w < workers; ++w) {
        int size = chunk + (w < static_cast<unsigned>(rem) ? 1 : 0);
        int from = start;
        int to = start + size;
        start += size;

        pool.enqueue([&, w, from, to, h] {
            double sum = 0.0;
            for (int i = from; i < to; ++i) {
                double x0 = a + i * h;
                double x1 = x0 + h;
                sum += (f.eval(x0) + f.eval(x1)) * h / 2.0;
            }
            partial[w] = sum;
            {
                std::lock_guard<std::mutex> lock(doneMtx);
                if (--remaining == 0) {
                    doneCv.notify_one();
                }
            }
        });
    }

    {
        std::unique_lock<std::mutex> lock(doneMtx);
        doneCv.wait(lock, [&] { return remaining == 0; });
    }

    double total = 0.0;
    for (unsigned w = 0; w < workers; ++w) {
        total += partial[w];
    }
    delete[] partial;
    return total;
}

int main() {
    Quadratic f;
    double a = 2.0;
    double b = 20.0;

    unsigned workers = std::thread::hardware_concurrency();
    if (workers == 0) workers = 4;
    ThreadPool pool(workers);

    std::cout << "f(x) = 2x^2 + 3x + 1/2   [a=2, b=20]\n";
    std::cout << "Hilos en el pool: " << workers << "\n";
    std::cout << "Area exacta (analitica): 5931.0\n\n";

    std::cout << std::fixed << std::setprecision(12);
    double previous = 0.0;
    for (int n = 1; n <= 1000000; ++n) {
        double area = integrate(f, a, b, n, pool);
        if (n > 1 && area == previous) {
            std::cout << std::setprecision(6)
                      << "Se repite en N=" << n << " -> Area = " << area << "\n";
            break;
        }
        previous = area;
        if (n <= 10 || n % 20000 == 0) {
            std::cout << std::setprecision(12)
                      << "N=" << std::setw(8) << n << " Area = " << area << "\n";
        }
    }

    return 0;
}
