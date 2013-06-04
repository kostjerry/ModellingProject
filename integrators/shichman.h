#ifndef SHICHMAN_H
#define SHICHMAN_H

#include <integrators/integratorbase.h>
#include <algorithms/predictors.h>
#include <algorithms/jacobi.h>
#include <algorithms/gauss.h>
#include <algorithms/op.h>
#include <math.h>

class Shichman : public IntegratorBase
{
public:
    Shichman();
    double **integrate();
private:
    double dMax, dMin;
    int kMax, kMin;

    double **getInitPoints(double hInt);
    double getFirstStepSize();
};

#endif // SHICHMAN_H
