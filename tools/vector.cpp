#include "vector.h"

Vector::Vector(int m)
{
    this->m = m;
    this->items = new double[m];
}

void Vector::init(double value)
{
    int i;
    for (i = 0; i < this->m; i++)
    {
        this->items[i] = value;
    }
}

void Vector::init(double *values)
{
    int i;
    for (i = 0; i < this->m; i++)
    {
        this->items[i] = values[i];
    }
}

Vector *Vector::copy()
{
    int i,
        m = this->m;
    double *items = this->items;
    Vector *vectorCopy = new Vector(m);

    for (i = 0; i < m; i++)
    {
        vectorCopy[i] = items[i];
    }

    return vectorCopy;
}

double &Vector::operator [](int i)
{
    if ((i < 0) || (i >= this->m))
    {
        throw "[Vector] Index out of range";
    }
    return this->items[i];
}

double Vector::operator *=(double scalar)
{
    int i,
        m = this->m;

    for (i = 0; i < m; i++)
    {
        this->items[i] *= scalar;
    }
}

double Vector::operator *=(Vector vector)
{
    int i,
        m = this->m;
    double sum = 0.0;
    double *items = this->items;

    for (i = 0; i < m; i++)
    {
        sum += items[i] * vector[i];
    }

    return sum;
}
