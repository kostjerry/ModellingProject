#include "eigenvalues.h"

Eigenvalues::Eigenvalues(double **matrix, int n)
{
    this->matrix = matrix;
    this->n = n;
    this->exactMethod = new IPM(this->matrix, this->n);
}

double Eigenvalues::getMin()
{
    return this->exactMethod->getMin();
}

double Eigenvalues::getMax()
{
    return this->exactMethod->getMax();
}

int Eigenvalues::getIterationsCount()
{
    return this->exactMethod->getIterationsCount();
}
