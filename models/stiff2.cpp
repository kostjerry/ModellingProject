#include "stiff2.h"
#include "math.h"

Stiff2::Stiff2()
{
    this->name = "Model 2 for stiffness exploration";
    this->size = 2;
    this->x0 = new double[2];
    this->x0[0] = 1.0;
    this->x0[1] = 1.0;
    this->tStart = 0.0;
    this->tStop = 2.0;
}

double* Stiff2::F(double *x, double t)
{
    double *res = new double[2];
    res[0] = -x[0];
    res[1] = -10000.1 * (x[0] + x[1]);
    return res;
}
