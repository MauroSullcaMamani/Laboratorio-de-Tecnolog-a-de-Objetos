import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
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
            double area = TrapezoidIntegrator.integrate(f, a, b, n, pool);
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
