#include "powermethod.h"
#include <algorithms/op.h>

PowerMethod::PowerMethod(double **matrix, int n) : ExactMethodBase(matrix, n)
{
}

double PowerMethod::getMax()
{
    if (this->max == NULL)
    {
        bool    finish;
        int     i,
                j,
                iterationsCount = 0,
                eigenvalueIndex = 0,
                n = this->n;
        double  *eigenVectorK = new double[n],
                *eigenVectorK1,
                itemMaxAbs,
                itemMax,
                itemCurAbs,
                itemCur,
                eigenvalue = 0.0,
                eigenvalueOld,
                **matrix = this->matrix;

        // Init eigenvector
        for (i = 0; i < n; i++)
        {
            eigenVectorK[i] = 1.0 + double(i);
        }

        while (true)
        {
            iterationsCount++;

            eigenVectorK1 = new double[n];

            for (i = 0; i < n; i++)
            {
                eigenVectorK1[i] = 0.0;
                for (j = 0; j < n; j++)
                {
                    eigenVectorK1[i] += matrix[i][j] * eigenVectorK[j];
                }
            }

            // Get eigenvalue
            eigenvalueOld = eigenvalue;
            eigenvalue = eigenVectorK1[eigenvalueIndex] / eigenVectorK[eigenvalueIndex];

            if (fabs(eigenvalueOld - eigenvalue) < this->eps) {
                break;
            }

            if (iterationsCount >= this->maxIterationsCount)
            {
                std::cout << "[PM] Max iterations count reached" << endl;
                break;
            }

            // Break condition
            finish = true;
            for (i = 0; i < n; i++)
            {
                if (fabs(eigenVectorK[i] - eigenVectorK1[i]) >= this->eps)
                {
                    finish = false;
                    break;
                }
            }

            if (finish == true)
            {
                break;
            }

            delete [] eigenVectorK;
            eigenVectorK = eigenVectorK1;

            // Norm eigenVectorK
            if (iterationsCount % 1 == 0)
            {
                for (i = 0; i < n; i++)
                {
                    itemCur = eigenVectorK[i];
                    itemCurAbs = fabs(itemCur);
                    if ((i == 0) || (itemCurAbs > itemMaxAbs))
                    {
                        itemMaxAbs = itemCurAbs;
                        itemMax = itemCur;
                        eigenvalueIndex = i;
                    }
                }
                if (itemMax != 0)
                {
                    for (i = 0; i < n; i++)
                    {
                        eigenVectorK[i] /= itemMax;
                    }
                }
                else
                {
                    std::cout << "[PM] Eigenvector became zero" << endl;
                    break;
                }
            }
        }

        this->iterationsCount = iterationsCount;

        this->max = eigenvalue;
    }
    return this->max;
}

double PowerMethod::getMin()
{
    if (this->min == NULL)
    {
        int     i,
                n = this->n;
        Op      *op = new Op();
        double  **b = op->createMatrix(n),
                max = this->getMax(),
                min;

        op->copyMatrix(b, this->matrix, n);

        for (i = 0; i < n; i++)
        {
            b[i][i] -= max;
        }

        PowerMethod *pm = new PowerMethod(b, n);
        min = max + pm->getMax();
        this->min = min;
    }
    return this->min;
}

