#ifndef NORMMETHOD_H
#define NORMMETHOD_H

#include <algorithms/eigenvalues/estimate/estimatemethodbase.h>

class NormMethod : public EstimateMethodBase
{
public:
    NormMethod(double **matrix, int n);
    void calculate();
};

#endif // NORMMETHOD_H
