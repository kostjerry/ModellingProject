#include "modelbase.h"

ModelBase::ModelBase()
{
}

int ModelBase::getSize()
{
    return this->size;
}

double* ModelBase::F(double *x, double t)
{
    throw "Not implemented";
}
