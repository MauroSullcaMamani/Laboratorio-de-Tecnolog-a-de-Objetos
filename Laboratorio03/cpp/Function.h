#pragma once

class Function {
public:
    virtual double eval(double x) const = 0;
    virtual ~Function() = default;
};
