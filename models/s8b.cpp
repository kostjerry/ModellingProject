#include "s8b.h"

S8b::S8b()
{
    this->name = "S8 (class B, S = 10^2) from Dana Petcu";
    this->size = 4;
    this->x0 = new double[4];
    this->x0[0] = 1.0;
    this->x0[1] = 0.0;
    this->x0[2] = 1.0;
    this->x0[3] = 0.0;
    this->tStart = 0.0;
    this->tStop = 20.0;
}

double* S8b::F(double *x, double t)
{
    double *res = new double[4];
    res[0] = -x[0] + x[1];
    res[1] = -100.0 * x[0] - x[1];
    res[2] = -100.0 * x[2] + x[3];
    res[3] = -10000.0 * x[2] - 100.0 * x[3];
    return res;
}
