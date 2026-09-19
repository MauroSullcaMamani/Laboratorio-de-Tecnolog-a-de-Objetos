#include "TrapezoidIntegrator.h"
#include <condition_variable>
#include <mutex>

double TrapezoidIntegrator::integrate(const Function &f, double a, double b, int n, ThreadPool &pool) {
    double h = (b - a) / n;

    unsigned workers = std::thread::hardware_concurrency();
    if (workers == 0) workers = 4;
    if (static_cast<unsigned>(n) < workers) workers = static_cast<unsigned>(n);

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
