#include "ipm.h"

/*
 * Метод зворотніх ітерацій зі зсувом (за Калиткиним)
 */

IPM::IPM(double **matrix, int n) : ExactMethodBase(matrix, n)
{
    this->modification = "default";
    this->estimateMethod = new NormMethod(matrix, n);
    this->estimateMethod->calculate();
}

double IPM::getNear(double eigenvalue)
{
    const int FIXED_LANDSLIDE_ITERATIONS_COUNT = 5;
    const int MAX_ITERATIONS_COUNT = 100;

    Op *op = new Op();
    Gauss *gaussAlgo = new Gauss();
    bool    finish;
    int     i,
            iterationsCount = 0,
            eigenvalueIndex = 0,
            n = this->n;
    double  *eigenVectorK = new double[n],
            *eigenVectorK1,
            itemMaxAbs,
            itemMax,
            itemCurAbs,
            itemCur,
            delta,
            eigenvalueInitial = eigenvalue,
            **matrix = this->matrix,
            **gaussMatrix = op->createMatrix(n),
            *gaussVector = op->createVector(n);

    // Init eigenvector
    for (i = 0; i < n; i++)
    {
        eigenVectorK[i] = 1.0 + double(i);
    }

    while (true)
    {
        iterationsCount++;

        op->copyMatrix(gaussMatrix, matrix, n);

        if (iterationsCount <= FIXED_LANDSLIDE_ITERATIONS_COUNT) {
            for (i = 0; i < n; i++) {
                gaussMatrix[i][i] -= eigenvalueInitial;
            }
        }
        else {
            for (i = 0; i < n; i++) {
                gaussMatrix[i][i] -= eigenvalue;
            }
        }

        op->copyVector(gaussVector, eigenVectorK, n);

        eigenVectorK1 = gaussAlgo->solve(gaussMatrix, gaussVector, n);

        if (eigenVectorK1 == 0) // Matrix is poorly conditioned (i.e. there is at least one row of zeros)
        {
            std::cout << "[IPM] GAUSS has detected poorly conditioned matrix!!!" << endl;
            break;
        }

        // Get eigenvalue
        delta = eigenVectorK[eigenvalueIndex] / eigenVectorK1[eigenvalueIndex];
        if (iterationsCount <= FIXED_LANDSLIDE_ITERATIONS_COUNT) {
            eigenvalue = eigenvalueInitial + delta;
        }
        else {
            eigenvalue += delta;
        }

        if (iterationsCount >= MAX_ITERATIONS_COUNT)
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
                std::cout << "!!! Eigenvector became zero !!!" << endl;
                break;
            }
        }
    }

    this->iterationsCount = iterationsCount;

    return eigenvalue;
}

double IPM::getMax()
{
    if (this->max == NULL)
    {
        this->max = this->getNear(this->estimateMethod->getMax());
    }
    return this->max;
}

double IPM::getMin()
{
    if (this->min == NULL)
    {
        this->min = this->getNear(this->estimateMethod->getMin());
    }
    return this->min;
}
