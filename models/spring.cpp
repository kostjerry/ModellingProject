#include "spring.h"

Spring::Spring()
{
    this->name = "Spring mass model";
    this->size = 2;
    this->x0 = new double[2];
    this->x0[0] = 0.0;
    this->x0[1] = 1.0;
    this->tStart = 0.0;
    this->tStop = 10.0;
}

double* Spring::F(double *x, double t)
{
    double* res = new double[2];
    res[0] = x[1];
    res[1] = -x[0];
    return res;
}
