#include "spring.h"

Spring::Spring()
{
    this->name = "Spring mass model";
    this->size = 2;
}

double* Spring::F(double *x, double t)
{
    double* res = new double[2];
    res[0] = x[1];
    res[1] = -x[0];
    return res;
}
