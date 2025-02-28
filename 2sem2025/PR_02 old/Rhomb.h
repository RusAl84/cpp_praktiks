#pragma once
#include "Shape.h"
#include <math.h>
class Rhomb :
    public Shape
{
private:
    double D, d;

public:
    Rhomb() : Shape("Ромб")
    {
        D = 0;
        d = 0;
    }
    Rhomb(double D, double d) : Shape("Ромб")
    {
        this->D = D;
        this->d = d;
    }
    double Area() const override
    {
        return (D * d) / 2;
    }
    double Perimetr() const override
    {
        return 2 * sqrt(pow(D, 2) + pow(d, 2));
    }
};

