#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
private:
    int m;
    double *items;
public:
    Vector(int m);
    Vector *copy();
    double &operator[](int i);
    double operator*=(double scalar);
    double operator*=(Vector vector);
    void init(double value);
    void init(double *values);
};

#endif // VECTOR_H
