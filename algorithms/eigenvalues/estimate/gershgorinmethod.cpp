#include "gershgorinmethod.h"

GershgorinMethod::GershgorinMethod(double **matrix, int n)
{
    this->matrix = matrix;
    this->n = n;
}

void GershgorinMethod::calculate()
{
    int i,
        j;
    double max, min;
    double sum, sub;
    for (i = 0; i < this->n; i++)
    {
        sum = 0.0;
        sub = 0.0;
        for (j = 0; j < this->n; j++)
        {
            sum += fabs(this->matrix[i][j]);
            sub += ((i == j) ? -1.0 : 1.0) * fabs(this->matrix[i][j]);
        }
        sub *= -1.0;
        if ((i == 0) || (sum > max))
        {
            max = sum;
        }
        if ((i == 0) || (sub < min))
        {
            min = sub;
        }
    }
    if (min < 0) min = 0.001;

    this->min = min;
    this->max = max;
    this->calculated = true;
}


