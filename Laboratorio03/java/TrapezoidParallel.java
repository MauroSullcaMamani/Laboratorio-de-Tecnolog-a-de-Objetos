import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class TrapezoidParallel {

    interface Function {
        double eval(double x);
    }

    static class Quadratic implements Function {
        @Override
        public double eval(double x) {
            return 2.0 * x * x + 3.0 * x + 0.5;
        }
    }

    static class TrapezoidTask implements Callable<Double> {
        private final Function f;
        private final double a;
        private final double h;
        private final int start;
        private final int end;

        TrapezoidTask(Function f, double a, double h, int start, int end) {
            this.f = f;
            this.a = a;
            this.h = h;
            this.start = start;
            this.end = end;
        }

        @Override
        public Double call() {
            double sum = 0.0;
            for (int i = start; i < end; i++) {
                double x0 = a + i * h;
                double x1 = x0 + h;
                sum += (f.eval(x0) + f.eval(x1)) * h / 2.0;
            }
            return sum;
        }
    }

    static double integrate(Function f, double a, double b, int n, ExecutorService pool)
            throws Exception {
        double h = (b - a) / n;
        int workers = Runtime.getRuntime().availableProcessors();
        if (workers > n) {
            workers = n;
        }
        int chunk = n / workers;
        int rem = n % workers;

        List<Future<Double>> futures = new ArrayList<>();
        int start = 0;
        for (int w = 0; w < workers; w++) {
            int size = chunk + (w < rem ? 1 : 0);
            futures.add(pool.submit(new TrapezoidTask(f, a, h, start, start + size)));
            start += size;
        }

        double total = 0.0;
        for (Future<Double> future : futures) {
            total += future.get();
        }
        return total;
    }

    public static void main(String[] args) throws Exception {
        Function f = new Quadratic();
        double a = 2.0;
        double b = 20.0;

        int workers = Runtime.getRuntime().availableProcessors();
        ExecutorService pool = Executors.newFixedThreadPool(workers);

        System.out.println("f(x) = 2x^2 + 3x + 1/2   [a=2, b=20]");
        System.out.println("Threads en el pool: " + workers);
        System.out.println("Area exacta (analitica): 5931.0");
        System.out.println();

        double previous = 0.0;
        for (int n = 1; n <= 1_000_000; n++) {
            double area = integrate(f, a, b, n, pool);
            if (n > 1 && area == previous) {
                System.out.printf("Se repite en N=%d -> Area = %.6f%n", n, area);
                break;
            }
            previous = area;
            if (n <= 10 || n % 20000 == 0) {
                System.out.printf("N=%-8d Area = %.12f%n", n, area);
            }
        }

        pool.shutdown();
    }
}
