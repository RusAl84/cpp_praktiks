#pragma once
#include "Shape.h"
class Parallelogram :
    public Shape
{
private:
    double a, b, angle;

public:
    Parallelogram() : Shape("ֿאנאככוכמדנאלל")
    {
        a = 0;
        b = 0;
        angle = 0;
    }
    Parallelogram(double _a, double _b, double _angle) : Shape("ֿאנאככוכמדנאלל")
    {
        this->a = _a;
        this->b = _b;
        this->angle = _angle;
    }
    double Area() const override
    {
        double S = a * b * sin(angle);
        return S;
    }
    double Perimetr() const override
    {
        return 2*(a + b);
    }


};

