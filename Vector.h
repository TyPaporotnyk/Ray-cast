//
// Created by Даниил on 06.04.2022.
//

#ifndef STEP_VECTOR_H
#define STEP_VECTOR_H


struct Vector
{
    float x;
    float y;

    Vector() = default;
    Vector(float x, float y) : x(x), y(y) {}

    Vector operator+(Vector v);
    Vector operator+(float v);
    Vector operator-(float v);
    Vector operator*(float v);
    void operator= (Vector v);

    float abs();
    void normalize();
};


#endif //STEP_VECTOR_H
