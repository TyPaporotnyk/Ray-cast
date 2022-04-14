//
// Created by Даниил on 06.04.2022.
//

#include "Vector.h"
#include <cmath>

float Vector::abs()
{
    return sqrt(x*x+y*y);
}

Vector Vector::operator+(float v)
{
    return {x+v, y+v};
}

Vector Vector::operator-(float v)
{
    return {x-v, y-v};
}

Vector Vector::operator*(float v)
{
    return {x*v, y*v};
}

void Vector::normalize()
{
    float len = abs();
    x = x/len;
    y = y/len;
}

float Vector::abs(Vector v)
{
    return sqrt(pow(v.x-x,2)+pow(v.y-y,2));
}

void Vector::operator=(Vector v)
{
    x = v.x;
    y = v.y;
}

Vector Vector::operator+(Vector v)
{
    return {x+v.x, y+v.y};
}

