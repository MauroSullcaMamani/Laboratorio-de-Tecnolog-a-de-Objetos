package main

import "runtime"

type TrapezoidIntegrator struct{}

func (TrapezoidIntegrator) Integrate(f Function, a, b float64, n int) float64 {
	h := (b - a) / float64(n)

	workers := runtime.NumCPU()
	if workers > n {
		workers = n
	}
	chunk := n / workers
	rem := n % workers

	jobs := make(chan Job, workers)
	results := make(chan float64, workers)

	for w := 0; w < workers; w++ {
		go func() {
			for j := range jobs {
				sum := 0.0
				for i := j.Start; i < j.End; i++ {
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
		jobs <- Job{Start: start, End: start + size}
		start += size
	}
	close(jobs)

	total := 0.0
	for w := 0; w < workers; w++ {
		total += <-results
	}
	return total
}
