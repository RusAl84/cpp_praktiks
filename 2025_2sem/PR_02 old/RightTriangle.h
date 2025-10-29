#pragma once
#include "Shape.h"
class RightTriangle :
    public Shape
{
private:
    double a, b, angle;

public:
    RightTriangle() : Shape("Прямоугольный треугольник")
    {
        a = 0;
        b = 0;
        angle = 0;
    }
    RightTriangle(double _a, double _b, double _angle) : Shape("Прямоугольный треугольник")
    {
        this->a = _a;
        this->b = _b;
        this->angle = _angle;
    }
    double Area() const override
    {
        return 0.5*a*b;
    }
    double Perimetr() const override
    {
        double c = sqrt(a * a + b * b);
        return a+b+c;
    }
};

