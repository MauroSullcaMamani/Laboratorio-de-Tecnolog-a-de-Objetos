import java.util.concurrent.Callable;

public class TrapezoidTask implements Callable<Double> {
    private final Function f;
    private final double a;
    private final double h;
    private final int start;
    private final int end;

    public TrapezoidTask(Function f, double a, double h, int start, int end) {
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
