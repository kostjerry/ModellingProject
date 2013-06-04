#include "stiff.h"
#include "math.h"

Stiff::Stiff()
{
    this->name = "Model for stiffness exploration";
    this->size = 1;
    this->x0 = new double[1];
    this->x0[0] = 1.0;
    this->tStart = 0.0;
    this->tStop = 10.0;
}

double* Stiff::F(double *x, double t)
{
    double *res = new double[1];
    res[0] = -2000.0 * t * (x[0] - cos(t)) - sin(t);
    return res;
}
