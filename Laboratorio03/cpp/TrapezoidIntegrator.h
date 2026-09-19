#pragma once

#include "Function.h"
#include "ThreadPool.h"

class TrapezoidIntegrator {
public:
    static double integrate(const Function &f, double a, double b, int n, ThreadPool &pool);
};
