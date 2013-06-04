#include "fdn.h"

FDN::FDN()
{
    this->name = "FDN";
}

double** FDN::integrate()
{
    this->initIntegration();

    // TODO ...
}

double **FDN::getInitPoints(double hInt)
{
    int i;
    int modelSize = this->model->getSize();
    double **x = new double*[2];
    x[0] = new double[modelSize];
    x[1] = this->x0;
    double *f = this->model->F(x[1], this->tStart);
    for (i = 0; i < modelSize; i++)
    {
        // Back step by using Explicit Euler
        x[0][i] = x[1][i] - hInt * f[i];
    }
    return x;
}
