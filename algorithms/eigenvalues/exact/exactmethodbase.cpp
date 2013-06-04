#include "exactmethodbase.h"

ExactMethodBase::ExactMethodBase(double **matrix, int n)
{
    this->maxIterationsCount = 100;
    this->eps = 1E-3;
    this->matrix = matrix;
    this->n = n;
}

double ExactMethodBase::getMax()
{
    throw "Not implemented";
}

double ExactMethodBase::getMin()
{
    throw "Not implemented";
}

int ExactMethodBase::getIterationsCount()
{
    return this->iterationsCount;
}
