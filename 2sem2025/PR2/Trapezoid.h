#pragma once
#include "Shape.h"
class Trapezoid :
    public Shape
{
private:
    double a, b, h;
public:
    Trapezoid() : Shape("Трапеция")
    {
        a = 0.00;
        b = 0.00;
        h = 0.00;
    }
    Trapezoid(double a, double b, double h) : Shape("Трапеция")
    {
        this->a = a;
        this->b = b;
        this->h = h;
    }
    double Area() const override
    {
        return (a + b) * (h / 2);
    }
    double Perimetr() const override
    {
        return (a + b + 2 * h);
    }
};

