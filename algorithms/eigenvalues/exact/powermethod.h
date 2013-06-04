#ifndef POWERMETHOD_H
#define POWERMETHOD_H

#include <algorithms/eigenvalues/exact/exactmethodbase.h>

class PowerMethod : public ExactMethodBase
{
public:
    PowerMethod(double **matrix, int n);
    double getMax();
    double getMin();
};

#endif // POWERMETHOD_H
