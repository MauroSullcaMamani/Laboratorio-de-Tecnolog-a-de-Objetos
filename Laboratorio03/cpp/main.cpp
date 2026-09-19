#include "Quadratic.h"
#include "ThreadPool.h"
#include "TrapezoidIntegrator.h"
#include <iomanip>
#include <iostream>

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
        double area = TrapezoidIntegrator::integrate(f, a, b, n, pool);
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
