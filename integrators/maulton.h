#ifndef MAULTON_H
#define MAULTON_H

#include <integrators/integratorbase.h>
#include <algorithms/predictors.h>
#include <algorithms/jacobi.h>
#include <algorithms/gauss.h>
#include <algorithms/op.h>
#include <math.h>

class Maulton : public IntegratorBase
{
public:
    Maulton();
    double **integrate();
private:
    double dMax, dMin;
    int kMax, kMin;

    double **getInitPoints(double hInt);
    double getFirstStepSize();
};

#endif // MAULTON_H
