#include "spm.h"
#include <algorithms/op.h>


SPM::SPM(double **matrix, int n) : ExactMethodBase(matrix, n)
{
}

double SPM::getMax()
{
    if (this->max == NULL)
    {
        int     i,
                j,
                iterationsCount = 10,
                n = this->n;
        Op      *op = new Op();
        double
                eigenvalue = 0.0,
                **matrix = this->matrix,
                **matrixTemp = op->createMatrix(n),
                **matrixK = op->createMatrix(n),
                **matrixKM1 = op->createMatrix(n),
                **matrixT = op->createMatrix(n),
                **matrixTTemp = op->createMatrix(n),
                **matrixTK = op->createMatrix(n),
                *eigenvector = op->createVector(n),
                *v1 = op->createVector(n),
                *v2 = op->createVector(n),
                *v3 = op->createVector(n);

        for (i = 0; i < n; i++)
        {
            eigenvector[i] = 1.0 + double(i);
        }

        op->copyMatrix(matrixKM1, matrix, n);
        op->transposeMatrix(matrixT, matrix, n);
        op->copyMatrix(matrixTK, matrixT, n);

        for (i = 0; i < iterationsCount - 1; i++)
        {
            op->copyMatrix(matrixTemp, matrixKM1, n);
            op->mulMatrix(matrixKM1, matrixTemp, matrix, n);

            op->copyMatrix(matrixTTemp, matrixTK, n);
            op->mulMatrix(matrixTK, matrixTTemp, matrixT, n);
        }
        op->mulMatrix(matrixK, matrixKM1, matrix, n);
        op->copyMatrix(matrixTTemp, matrixTK, n);
        op->mulMatrix(matrixTK, matrixTTemp, matrixT, n);

        op->mulMatrixVector(v1, matrixK, eigenvector, n);
        op->mulMatrixVector(v2, matrixTK, eigenvector, n);
        op->mulMatrixVector(v3, matrixKM1, eigenvector, n);

        eigenvalue = (op->mulVector(v1, v2, n)) / (op->mulVector(v3, v2, n));

        this->iterationsCount = iterationsCount;

        this->max = eigenvalue;
    }
    return this->max;
}

double SPM::getMin()
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

        SPM *pm = new SPM(b, n);
        min = max + pm->getMax();
        this->min = min;
    }
    return this->min;
}

