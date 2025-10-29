#pragma once
#include "Shape.h"
#include <math.h> 
#include <corecrt_math_defines.h>
using namespace std;
class Triangle :
    public Shape
{
private:
    double g, a, b;

public:
    Triangle() : Shape("Треугольник")
    {
        this->g = 0.00;
        this->a = 0.00;
        this->b = 0.00;
    }
    Triangle(double g, double a, double b) : Shape("Треугольник")
    {
        this->g = g;
        this->a = a;
        this->b = b;
    }
    double Area() const override
    {
        return (-1) * (pow(a, 2) / 2) * ((sin(b) * sin(a)) / sin(90));// * 180 / M_PI);
    }
    double Perimetr() const override
    {
        double k1 = (-1) * g * (sin(a) * 180 / M_PI);
        double k2 = g * (sin(b) * 180 / M_PI);
        return (k1 + k2 + g);
    }
};

