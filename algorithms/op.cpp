#include "op.h"

Op::Op()
{
}

double **Op::createMatrix(int n)
{
    int i;
    double **matrix = new double*[n];
    for (i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
    }
    return matrix;
}

double *Op::createVector(int n)
{
    double *vector = new double[n];
    return vector;
}

void Op::mulMatrixVector(double *dest, double **matrix, double *vector, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        dest[i] = 0.0;
        for (j = 0; j < n; j++)
        {
            dest[i] += matrix[i][j] * vector[j];
        }
    }
}

double Op::mulVector(double *v1, double *v2, int n)
{
    double res = 0.0;
    int i;
    for (i = 0; i < n; i++)
    {
        res += v1[i] * v2[i];
    }
    return res;
}

void Op::copyMatrix(double **dest, double **source, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dest[i][j] = source[i][j];
        }
    }
}

void Op::copyVector(double *dest, double *source, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        dest[i] = source[i];
    }
}

void Op::mulMatrix(double **dest, double **source1, double **source2, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dest[i][j] = 0.0;
            for (k = 0; k < n; k++)
            {
                dest[i][j] += source1[i][k] * source2[k][j];
            }
        }
    }
}

void Op::transposeMatrix(double **dest, double **source, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dest[i][j] = source[j][i];
        }
    }
}
