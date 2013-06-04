#include "s27d.h"

S27d::S27d()
{
    this->name = "S27 (class D, S = 3*10^7) from Dana Petcu";
    this->size = 3;
    this->x0 = new double[3];
    this->x0[0] = 1.0;
    this->x0[1] = 0.0;
    this->x0[2] = 0.0;
    this->tStart = 0.0;
    this->tStop = 1.0;
}

double* S27d::F(double *x, double t)
{
    double *res = new double[3];
    res[0] = -x[0] + 100000000.0 * x[2] * (1.0 - x[0]);
    res[1] = -10.0 * x[1] + 30000000.0 * x[2] * (1.0 - x[1]);
    res[2] = -res[0] - res[1];
    return res;
}
