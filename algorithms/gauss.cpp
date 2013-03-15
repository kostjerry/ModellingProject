#include "gauss.h"

Gauss::Gauss()
{
    this->eps = 1e-7;
}

double *Gauss::solve(double **a, double *b, int n)
{
    double *x = new double[n];
    int i, j, k;
    double r;
    int nPrev = n - 1;

    if (n == 1)
    {
        if (a[0][0] < this->eps)
        {
            throw "[Gauss] Matrix is poorly conditioned";
        }
        else
        {
            x[0] = b[0] / a[0][0];
            return x;
        }
    }
    else
    {
        for (i = 0; i < nPrev; i++)
        {
            k = i;
            r = fabs(a[i][i]);
            for (j = i + 1; j < n; j++)
            {
                if (fabs(a[j][i]) >= r)
                {
                    k = j;
                    r = fabs(a[j][i]);
                }
            }

            if (r < this->eps)
            {
                throw "[Gauss] Matrix is poorly conditioned";
            }

            if (k != i)
            {
                r = b[k];
                b[k] = b[i];
                b[i] = r;
                for (j = i; j < n; j++)
                {
                    r = a[k][j];
                    a[k][j] = a[i][j];
                    a[i][j] = r;
                }
            }

            r = a[i][i];
            b[i] = b[i] / r;

            for (j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] / r;
            }

            for (k = i + 1; k < n; k++)
            {
                r = a[k][i];
                b[k] = b[k] - r * b[i];
                a[k][i] = 0.0;
                for (j = i + 1; j < n; j++)
                {
                    a[k][j] = a[k][j] - r * a[i][j];
                }
            }
        }

        if (fabs(a[nPrev][nPrev]) <= this->eps)
        {
            throw "[Gauss] Matrix is poorly conditioned";
        }

        x[nPrev] = b[nPrev] / a[nPrev][nPrev];
        for (i = n - 2; i >= 0; i--)
        {
            r = b[i];
            for (j = i + 1; j < n; j++)
            {
                r -= a[i][j] * x[j];
            }
            x[i] = r;
        }
        return x;
    }
}
