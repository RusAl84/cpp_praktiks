#pragma once
#include "Shape.h"
class RegularPolygon :
    public Shape
{
private:
    double a, r, count;

public:
    RegularPolygon() : Shape("Правильный многоугольник")
    {
        a = 0;
        r = 0;
        count = 0;
    }
    RegularPolygon(double _a, double _r, double _count) : Shape("Правильный многоугольник")
    {
        this->a = _a;
        this->r = _r;
        this->count = _count;
    }
    double Area() const override
    {
        double P = a * count;
        return 0.5 * P * r;
    }
    double Perimetr() const override
    {
       
        return a * count;
    }
};

