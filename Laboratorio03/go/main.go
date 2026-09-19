package main

import (
	"fmt"
	"runtime"
)

type Function interface {
	Eval(x float64) float64
}

type Quadratic struct{}

func (Quadratic) Eval(x float64) float64 {
	return 2.0*x*x + 3.0*x + 0.5
}

type job struct {
	start int
	end   int
}

func trapezoid(f Function, a, b float64, n int) float64 {
	h := (b - a) / float64(n)

	workers := runtime.NumCPU()
	if workers > n {
		workers = n
	}
	chunk := n / workers
	rem := n % workers

	jobs := make(chan job, workers)
	results := make(chan float64, workers)

	// Worker pool: cada goroutine procesa jobs del canal hasta que se cierra.
	for w := 0; w < workers; w++ {
		go func() {
			for j := range jobs {
				sum := 0.0
				for i := j.start; i < j.end; i++ {
					x0 := a + float64(i)*h
					x1 := x0 + h
					sum += (f.Eval(x0) + f.Eval(x1)) * h / 2.0
				}
				results <- sum
			}
		}()
	}

	start := 0
	for w := 0; w < workers; w++ {
		size := chunk
		if w < rem {
			size++
		}
		jobs <- job{start: start, end: start + size}
		start += size
	}
	close(jobs)

	total := 0.0
	for w := 0; w < workers; w++ {
		total += <-results
	}
	return total
}

func main() {
	f := Quadratic{}
	a, b := 2.0, 20.0

	fmt.Printf("f(x) = 2x^2 + 3x + 1/2   [a=2, b=20]\n")
	fmt.Printf("Goroutines (worker pool): %d\n", runtime.NumCPU())
	fmt.Println("Area exacta (analitica): 5931.0")
	fmt.Println()

	previous := 0.0
	for n := 1; n <= 1000000; n++ {
		area := trapezoid(f, a, b, n)
		if n > 1 && area == previous {
			fmt.Printf("Se repite en N=%d -> Area = %.6f\n", n, area)
			break
		}
		previous = area
		if n <= 10 || n%20000 == 0 {
			fmt.Printf("N=%-8d Area = %.12f\n", n, area)
		}
	}
}
