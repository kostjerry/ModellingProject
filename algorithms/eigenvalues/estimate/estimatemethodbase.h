#ifndef ESTIMATEMETHODBASE_H
#define ESTIMATEMETHODBASE_H

#include <math.h>

class EstimateMethodBase
{
protected:
    double **matrix;
    int n;
    double min;
    double max;
    bool calculated = false;
public:
    EstimateMethodBase();
    virtual void calculate();
    double getMax();
    double getMin();
};

#endif // ESTIMATEMETHODBASE_H
