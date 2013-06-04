#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

class Vector
{
private:
    int n;
    double *items;
public:
    Vector(int n);
    Vector *copy();
    double &operator[](int i);
    //double operator*=(double scalar);
    //double operator*=(Vector vector);
    void init(double value);
    void init(double *values);
    double *toArray();
    double normByMax();
};

#endif // VECTOR_H
