#include "s19c.h"

S19c::S19c()
{
    this->name = "S19 (class C, S = 10^2) from Dana Petcu";
    this->size = 4;
    this->x0 = new double[4];
    this->x0[0] = 1.0;
    this->x0[1] = 1.0;
    this->x0[2] = 1.0;
    this->x0[3] = 1.0;
    this->tStart = 0.0;
    this->tStop = 20.0;
}

double* S19c::F(double *x, double t)
{
    double *res = new double[4];
    res[0] = -x[0] + x[1] * x[1] + x[2] * x[2] + x[3] * x[3];
    res[1] = -10.0 * x[1] + 10.0 * (x[2] * x[2] + x[3] * x[3]);
    res[2] = -40.0 * x[2] + 40.0 * (x[3] * x[3]);
    res[3] = -100.0 * x[3] + 2.0;
    return res;
}
