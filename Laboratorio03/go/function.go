package main

type Function interface {
	Eval(x float64) float64
}

type Quadratic struct{}

func (Quadratic) Eval(x float64) float64 {
	return 2.0*x*x + 3.0*x + 0.5
}
