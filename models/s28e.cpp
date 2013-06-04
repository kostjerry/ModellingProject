#include "s28e.h"

S28e::S28e()
{
    this->name = "S28 (class E, S = 5.2*10^6) from Dana Petcu";
    this->size = 2;
    this->x0 = new double[2];
    this->x0[0] = 2.0;
    this->x0[1] = 0.0;
    this->tStart = 0.0;
    this->tStop = 1.0;
}

double* S28e::F(double *x, double t)
{
    double *res = new double[2];
    res[0] = x[1];
    res[1] = 5.0 * (1.0 - x[0] * x[0]) * x[1] - x[0];
    return res;
}
