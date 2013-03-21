#ifndef IMPLICITEULER_H
#define IMPLICITEULER_H

#include <integrators/integratorbase.h>
#include <algorithms/predictors.h>
#include <algorithms/jacobi.h>
#include <algorithms/gauss.h>

class ImplicitEuler : public IntegratorBase
{
public:
    ImplicitEuler();
    double **integrate();
private:
    double **getInitPoints(double hInt);
};

#endif // IMPLICITEULER_H
