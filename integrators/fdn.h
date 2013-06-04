#ifndef FDN_H
#define FDN_H

#include <integrators/integratorbase.h>
#include <algorithms/predictors.h>
#include <algorithms/jacobi.h>
#include <algorithms/gauss.h>
#include <algorithms/op.h>
#include <math.h>

class FDN : public IntegratorBase
{
public:
    FDN();
    double **integrate();
private:
    double **getInitPoints(double hInt);
};

#endif // FDN_H
