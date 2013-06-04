#include "inversepowermethod.h"

InversePowerMethod::InversePowerMethod(double **matrix, int n) : ExactMethodBase(matrix, n)
{
    this->modification = "default";
    this->estimateMethod = new NormMethod(matrix, n);
    this->estimateMethod->calculate();
}

double InversePowerMethod::getMax()
{
    if (this->max == NULL)
    {
        this->max = this->getNear(this->estimateMethod->getMax());
    }
    return this->max;
}

double InversePowerMethod::getMin()
{
    if (this->min == NULL)
    {
        this->min = this->getNear(this->estimateMethod->getMin());
    }
    return this->min;
}

double InversePowerMethod::getNear(double eigenvalue)
{
    int n = this->n;
    double **matrix = this->matrix;

    int i, j;
    int iterationsCount = 0;
    bool finish;
    double *eigenVectorK = new double[n];
    double *eigenVectorK1;
    Gauss *gaussAlgo = new Gauss();
    double **gaussMatrix = new double*[n];
    double *gaussVector = new double[n];
    double  itemMaxAbs,
            itemMax,
            itemCurAbs,
            itemCur,
            numerator,
            denominator;

    // Init eigenvector
    for (i = 0; i < n; i++)
    {
        eigenVectorK[i] = -1.0;
    }

    // Init gaussMatrix
    for (i = 0; i < n; i++)
    {
        gaussMatrix[i] = new double[n];
    }

    while (true)
    {
        iterationsCount++;
        for (i = 0; i < n; i++)
        {
            gaussVector[i] = eigenVectorK[i];
            for (j = 0; j < n; j++)
            {
                gaussMatrix[i][j] = ((i == j) ? matrix[i][j] - eigenvalue : matrix[i][j]);
            }
        }
        eigenVectorK1 = gaussAlgo->solve(gaussMatrix, gaussVector, n);
        if (eigenVectorK1 == 0) // Matrix is poorly conditioned (i.e. there is at least one row of zeros)
        {
            std::cout << "GAUSS has detected poorly conditioned matrix!!!" << endl;
            break;
        }

        // Norm eigenVectorK1

        itemMaxAbs;
        itemMax;

        for (i = 0; i < n; i++)
        {
            itemCur = eigenVectorK1[i];
            itemCurAbs = fabs(itemCur);
            if ((i == 0) || (itemCurAbs > itemMaxAbs))
            {
                itemMaxAbs = itemCurAbs;
                itemMax = itemCur;
            }
        }
        if (itemMax != 0)
        {
            for (i = 0; i < n; i++)
            {
                eigenVectorK1[i] /= itemMax;
            }
        }
        else
        {
            // TODO: ???
        }

        if (iterationsCount >= this->maxIterationsCount)
        {
            std::cout << "Max iterations count reached" << endl;
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

        if (this->modification == "rayleigh")
        {
            // Calculate Rayleigh quotient
            numerator = 0.0;
            denominator = 0.0;
            for (i = 0; i < n; i++)
            {
                gaussVector[i] = 0.0;
                for (j = 0; j < n; j++)
                {
                    gaussVector[i] += matrix[i][j] * eigenVectorK[j];
                }
                numerator += gaussVector[i] * eigenVectorK[i];
                denominator += eigenVectorK[i] * eigenVectorK[i];
            }
            eigenvalue = numerator / denominator;
        }
        else
        {
            // Simple eigenvalue definition
            eigenvalue += 1.0 / itemMax;
        }
    }

    return eigenvalue;
}
