#include "matrix.h"

Matrix::Matrix(int n)
{
    int i;
    Vector **items = new Vector*[n];

    this->n = n;

    for (i = 0; i < n; i++)
    {
        items[i] = new Vector(n);
    }
    this->items = items;
}

Matrix *Matrix::copy()
{
    int i;
    Matrix *matrixCopy = new Matrix(this->n);

    for (i = 0; i < this->n; i++)
    {
        (*matrixCopy)[i] = *this->items[i]->copy();
    }

    return matrixCopy;
}

void Matrix::init(double **matrix)
{
    int i;
    for (i = 0; i < this->n; i++)
    {
        this->items[i]->init(matrix[i]);
    }
}

Vector &Matrix::operator [](int i)
{
    return *this->items[i];
}

Matrix &Matrix::operator *(double value)
{
    int i, j;
    Matrix *matrixNew = this->copy();

    for (i = 0; i < this->n; i++)
    {
        for (j = 0; j < this->n; j++)
        {
            (*matrixNew)[i][j] *= value;
        }
    }

    return (*matrixNew);
}

Matrix &Matrix::operator +(Matrix &matrix)
{
    int i, j;
    Matrix *matrixNew = this->copy();

    for (i = 0; i < this->n; i++)
    {
        for (j = 0; j < this->n; j++)
        {
            (*matrixNew)[i][j] += matrix[i][j];
        }
    }

    return (*matrixNew);
}

Matrix *Matrix::E(int n)
{
    int i, j;
    Matrix *matrix = new Matrix(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            (*matrix)[i][j] = ((i == j) ? 1.0 : 0.0);
        }
    }
    return matrix;
}
