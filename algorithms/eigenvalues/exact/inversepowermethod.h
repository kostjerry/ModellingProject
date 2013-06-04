#ifndef INVERSEPOWERMETHOD_H
#define INVERSEPOWERMETHOD_H

#include <algorithms/eigenvalues/exact/exactmethodbase.h>
#include <algorithms/eigenvalues/estimate/gershgorinmethod.h>

class InversePowerMethod : public ExactMethodBase
{
private:
    EstimateMethodBase *estimateMethod;
public:
    InversePowerMethod(double **matrix, int n);
    double getMax();
    double getMin();
    double getNear(double eigenvalue);
};

#endif // INVERSEPOWERMETHOD_H
