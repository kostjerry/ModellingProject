#include "predictors.h"

Predictors::Predictors()
{
}

double *Predictors::linear(double **history, double hPrev, double hNext, int modelSize)
{
    int i;
    double *xp = new double[modelSize];
    for (i = 0; i < modelSize; i++)
    {
        xp[i] = history[1][i] + (history[1][i] - history[0][i]) * hNext / hPrev;
    }
    return xp;
}
