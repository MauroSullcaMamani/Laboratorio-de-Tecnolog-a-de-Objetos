package main

import (
	"fmt"
	"runtime"
)

func main() {
	f := Quadratic{}
	a, b := 2.0, 20.0
	integrator := TrapezoidIntegrator{}

	fmt.Printf("f(x) = 2x^2 + 3x + 1/2   [a=2, b=20]\n")
	fmt.Printf("Goroutines (worker pool): %d\n", runtime.NumCPU())
	fmt.Println("Area exacta (analitica): 5931.0")
	fmt.Println()

	previous := 0.0
	for n := 1; n <= 1000000; n++ {
		area := integrator.Integrate(f, a, b, n)
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
