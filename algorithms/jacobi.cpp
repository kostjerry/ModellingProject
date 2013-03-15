#include "jacobi.h"

Jacobi::Jacobi(double eps)
{
    this->eps = eps;
}

double **Jacobi::get(ModelBase *model, double *x, double t)
{
    int i, j;
    int n = model->getSize();
    double q = this->eps / 1000.0;
    double *f = model->F(x, t);
    double *fNew = new double[n];
    double **jacobi = new double*[n];
    for (i = 0; i < n; i++)
    {
        jacobi[i] = new double[n];
    }
    for (i = 0; i < n; i++)
    {
        x[i] += q;
        fNew = model->F(x, t);
        for (j = 0; j < n; j++)
        {
            jacobi[j][i] = (fNew[j] - f[j]) / q;
        }
        x[i] -= q;
    }
    return jacobi;
}
