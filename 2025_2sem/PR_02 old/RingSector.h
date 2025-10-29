#pragma once
#include "Shape.h"
#include <math.h> 
#include <corecrt_math_defines.h>
class RingSector :
    public Shape
{
private:
    double R, r, angle;

public:
    RingSector() : Shape("Сектор кольца")
    {
        R = 0;
        r = 0;
        angle = 0;
    }
    RingSector(double _R, double _r, double _angle) : Shape("Сектор кольца")
    {
        this->R = _R;
        this->r = _r;
        this->angle = _angle;
    }
    double Area() const override
    {
        double d1 = M_PI * angle / 360;
        double d2 = R - r;
        return d1 * d2;
    }
    double Perimetr() const override
    {
        double d1 = 2*M_PI * r *  angle / 360;
        double d2 = 2*M_PI * 2 *  angle / 360;
        return r + R + d1 + d2;
    }
};

