#ifndef EXACTMETHODBASE_H
#define EXACTMETHODBASE_H

#include <algorithms/gauss.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithms/eigenvalues/estimate/estimatemethodbase.h>
#include <algorithms/eigenvalues/estimate/normmethod.h>

using namespace std;

class ExactMethodBase
{
protected:
    int maxIterationsCount = 100;
    int iterationsCount = -1;
    double eps = 1E-3;
    string modification = "default";
    double **matrix;
    int n;
    double  min = NULL,
            max = NULL;

public:
    ExactMethodBase(double **matrix, int n);
    virtual double getMax();
    virtual double getMin();
    int getIterationsCount();
};

#endif // EXACTMETHODBASE_H
