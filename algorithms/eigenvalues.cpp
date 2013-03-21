#include "eigenvalues.h"

Eigenvalues::Eigenvalues(double **matrix, int n)
{
    this->matrix = new Matrix(n);
    this->matrix->init(matrix);
    this->n = n;
    this->eps = 0.001;
}

double Eigenvalues::getMin()
{
    Vector *yK = new Vector(this->n);
    double lK = 0.0; // Initial eigenvalue
    yK->init(0.0); // Initial eigenvector
    Matrix *E = Matrix::E(n);
    *E = *E + *E;

}

double Eigenvalues::getMax()
{
    return 0;
}
