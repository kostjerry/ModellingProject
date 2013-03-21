#ifndef EIGENVALUES_H
#define EIGENVALUES_H

#include <tools/matrix.h>
#include <tools/vector.h>
#include <algorithms/gauss.h>

class Eigenvalues
{
private:
    Matrix *matrix;
    int n;
    double eps;
public:
    Eigenvalues(double **matrix, int n);
    double getMin();
    double getMax();
};

#endif // EIGENVALUES_H
