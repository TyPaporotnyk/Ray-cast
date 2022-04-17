//
// Created by Даниил on 06.04.2022.
//

#ifndef STEP_VECTOR_H
#define STEP_VECTOR_H


struct Vector
{
    double x;
    double y;

    Vector() = default;
    Vector(double x, double y) : x(x), y(y) {}

    Vector operator+(Vector v) const;
    Vector operator+(double v) const;
    Vector operator-(double v) const;
    Vector operator*(double v) const;
    Vector& operator=(Vector v);

    [[nodiscard]] double abs() const;
    void normalize();
};


#endif //STEP_VECTOR_H
