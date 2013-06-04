#ifndef GERSHGORINMETHOD_H
#define GERSHGORINMETHOD_H

#include <algorithms/eigenvalues/estimate/estimatemethodbase.h>

class GershgorinMethod : public EstimateMethodBase
{
public:
    GershgorinMethod(double **matrix, int n);
    void calculate();
};

#endif // GERSHGORINMETHOD_H
