import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;

public class TrapezoidIntegrator {
    public static double integrate(Function f, double a, double b, int n, ExecutorService pool)
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
}
