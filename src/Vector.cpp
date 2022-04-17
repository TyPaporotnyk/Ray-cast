//
// Created by Даниил on 06.04.2022.
//

#include "Vector.h"
#include <cmath>

double Vector::abs() const
{
    return sqrt(x*x+y*y);
}

Vector Vector::operator+(double v) const
{
    return {x+v, y+v};
}

Vector Vector::operator-(double v) const
{
    return {x-v, y-v};
}

Vector Vector::operator*(double v) const
{
    return {x*v, y*v};
}

void Vector::normalize()
{
    double len = abs();
    x = x/len;
    y = y/len;
}

Vector& Vector::operator=(Vector v)
{
    x = v.x;
    y = v.y;
    return *this;
}

Vector Vector::operator+(Vector v) const
{
    return {x+v.x, y+v.y};
}

