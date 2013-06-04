#ifndef IPM_H
#define IPM_H

#include <algorithms/eigenvalues/exact/exactmethodbase.h>
#include <algorithms/op.h>
#include <algorithms/eigenvalues/estimate/gershgorinmethod.h>

class IPM : public ExactMethodBase
{
private:
    EstimateMethodBase *estimateMethod;
public:
    IPM(double **matrix, int n);
    double getNear(double eigenvalue);
    double getMax();
    double getMin();
};

#endif // IPM_H
