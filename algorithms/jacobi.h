#ifndef JACOBI_H
#define JACOBI_H

#include <models/modelbase.h>

class Jacobi
{
public:
    Jacobi(double eps);
    double **get(ModelBase *model, double *x, double t);
private:
    double eps;
};

#endif // JACOBI_H
