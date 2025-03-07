#pragma once
#include "Shape.h"
#include <math.h> 
#include <corecrt_math_defines.h>
class IsoscelesTriangle :
    public Shape
{
private:
    double a, b, h;

public:
    IsoscelesTriangle() : Shape("Равнобедренный треугольник")
    {
        a = 0;
        b = 0;
        h = 0;
    }
    IsoscelesTriangle(double _a, double _b, double _h) : Shape("Равнобедренный треугольник")
    {
        this->a = _a;
        this->b = _b;
        this->h = _h;
    }
    double Area() const override
    {
        return 1/2*b*h;
    }
    double Perimetr() const override
    {
        return a+a+b;
    }
};

