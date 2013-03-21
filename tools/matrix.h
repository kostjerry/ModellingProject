#ifndef MATRIX_H
#define MATRIX_H

#include <tools/vector.h>

class Matrix
{
private:
    int n;
    Vector **items;
public:
    Matrix(int n);
    Matrix *copy();
    void init(double **matrix);
    Vector &operator [](int i);
    Matrix &operator *(double value);
    Matrix &operator +(Matrix &matrix);
    static Matrix *E(int n);
};

#endif // MATRIX_H
