#include "modelbase.h"

ModelBase::ModelBase()
{
}

int ModelBase::getSize()
{
    return this->size;
}

void ModelBase::setX0(double *x0)
{
    this->x0 = x0;
}

void ModelBase::setTStart(double tStart)
{
    this->tStart = tStart;
}

void ModelBase::setTStop(double tStop)
{
    this->tStop = tStop;
}

double *ModelBase::getX0()
{
    return this->x0;
}

double ModelBase::getTStart()
{
    return this->tStart;
}

double ModelBase::getTStop()
{
    return this->tStop;
}

double* ModelBase::F(double *x, double t)
{
    throw "Not implemented";
}
