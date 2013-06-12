#include "c1.h"

C1::C1()
{
    this->name = "C1 from Zavorin";
    this->size = 3;
    this->x0 = new double[3];
    this->x0[0] = 1.0;
    this->x0[1] = 1.0;
    this->x0[2] = 1.0;
    this->tStart = 0.0;
    this->tStop = 10.0;
}

double* C1::F(double *x, double t)
{
    double *res = new double[3];
    double a = 1.0;
    double a_2 = a * a;
    double a_3 = a_2 * a;
    double lambda2 = 100.0;
    double lambda3 = 10000.0;
    double x0_2 = x[0] * x[0];
    double x1_2 = x[1] * x[1];

    res[0] = -x[0] + 2.0;
    res[1] = a_2 * x0_2 - lambda2 * x[1];
    res[2] = a_3 * (x0_2 + x1_2) - lambda3 * x[2];

    return res;
}
