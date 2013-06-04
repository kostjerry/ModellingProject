#ifndef SPM_H
#define SPM_H

#include <algorithms/eigenvalues/exact/exactmethodbase.h>

class SPM : public ExactMethodBase
{
public:
    SPM(double **matrix, int n);
    double getMax();
    double getMin();
};

#endif // SPM_H
