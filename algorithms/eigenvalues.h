#ifndef EIGENVALUES_H
#define EIGENVALUES_H

#include <algorithms/eigenvalues/exact/exactmethodbase.h>
#include <algorithms/eigenvalues/exact/inversepowermethod.h>
#include <algorithms/eigenvalues/exact/powermethod.h>
#include <algorithms/eigenvalues/exact/spm.h>
#include <algorithms/eigenvalues/exact/ipm.h>
#include <algorithms/eigenvalues/estimate/estimatemethodbase.h>
#include <algorithms/eigenvalues/estimate/gershgorinmethod.h>
#include <algorithms/eigenvalues/estimate/normmethod.h>
#include <algorithms/gauss.h>
#include <iostream>

class Eigenvalues
{
private:
    double **matrix;
    int n;
    ExactMethodBase *exactMethod;
public:
    Eigenvalues(double **matrix, int n);
    double getMin();
    double getMax();
    int getIterationsCount();
};

#endif // EIGENVALUES_H
