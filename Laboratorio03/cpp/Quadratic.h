#pragma once

#include "Function.h"

class Quadratic : public Function {
public:
    double eval(double x) const override;
};
