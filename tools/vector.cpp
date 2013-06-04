#include "vector.h"

Vector::Vector(int n)
{
    this->n = n;
    this->items = new double[n];
}

void Vector::init(double value)
{
    int i;
    for (i = 0; i < this->n; i++)
    {
        this->items[i] = value;
    }
}

void Vector::init(double *values)
{
    int i;
    for (i = 0; i < this->n; i++)
    {
        this->items[i] = values[i];
    }
}

Vector *Vector::copy()
{
    int i,
        n = this->n;
    double *items = this->items;
    Vector *vectorCopy = new Vector(n);

    for (i = 0; i < n; i++)
    {
        (*vectorCopy)[i] = items[i];
    }

    return vectorCopy;
}

double &Vector::operator [](int i)
{
    if ((i < 0) || (i >= this->n))
    {
        throw "[Vector] Index out of range";
    }
    return this->items[i];
}

double *Vector::toArray()
{
    return this->copy()->items;
}

double Vector::normByMax()
{
    int i;
    double  itemMaxAbs = 0.0,
            itemMax = 1.0,
            itemCurAbs,
            itemCur;
    for (i = 0; i < this->n; i++)
    {
        itemCur = this->items[i];
        itemCurAbs = fabs(itemCur);
        if (itemCurAbs > itemMaxAbs)
        {
            itemMaxAbs = itemCurAbs;
            itemMax = itemCur;
        }
    }

    if (itemMax != 0)
    {
        for (i = 0; i < this->n; i++)
        {
            this->items[i] /= itemMax;
        }
    }

    return itemMax;
}

/*
double Vector::operator *=(double scalar)
{
    int i,
        m = this->n;

    for (i = 0; i < m; i++)
    {
        this->items[i] *= scalar;
    }
}

double Vector::operator *=(Vector vector)
{
    int i,
        m = this->n;
    double sum = 0.0;
    double *items = this->items;

    for (i = 0; i < m; i++)
    {
        sum += items[i] * vector[i];
    }

    return sum;
}
*/
