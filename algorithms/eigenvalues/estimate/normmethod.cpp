#include "normmethod.h"

NormMethod::NormMethod(double **matrix, int n)
{
    this->matrix = matrix;
    this->n = n;
}

void NormMethod::calculate()
{
    int i, j;
    double norm = 0.0;

    for (i = 0; i < this->n; i++)
    {
        for (j = 0; j < this->n; j++)
        {
            norm += pow(this->matrix[i][j], 2.0);
        }
    }
    norm = sqrt(norm);

    this->min = 0.0;
    this->max = norm;
    this->calculated = true;
}
