#include "s4a.h"

S4a::S4a()
{
    int i;

    this->name = "S4 (class A, S = 2*10^4) from Dana Petcu";
    this->size = 9;
    this->x0 = new double[9];
    for (i = 0; i < 9; i++)
    {
        this->x0[i] = 0.0;
    }
    this->tStart = 0.0;
    this->tStop = 120.0;
}

double* S4a::F(double *x, double t)
{
    int i;
    double *res = new double[9];
    res[0] = -1800.0 * x[0] + 900 * x[1];
    for (i = 1; i < 8; i++)
    {
        res[i] = x[i - 1] - 2.0 * x[i] + x[i + 1];
    }
    res[8] = 1000.0 * x[7] - 2000.0 * x[8] + 10000.0;
    return res;
}
