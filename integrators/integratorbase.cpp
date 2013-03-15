#include "integratorbase.h"

IntegratorBase::IntegratorBase()
{
}

double** IntegratorBase::integrate()
{
    throw "Not implemented";
}

void IntegratorBase::setModel(ModelBase *model)
{
    this->model = model;
}

void IntegratorBase::setX0(double* x0)
{
    this->x0 = x0;
}

void IntegratorBase::setTStart(double tStart)
{
    this->tStart = tStart;
}

void IntegratorBase::setTStop(double tStop)
{
    this->tStop = tStop;
}

void IntegratorBase::setEps(double eps)
{
    this->eps = eps;
}

void IntegratorBase::setNGraphic(int nGraphic)
{
    this->nGraphic = nGraphic;
}

double** IntegratorBase::createResultsArray()
{
    int i;
    int nGraphic = this->nGraphic;
    int modelSize = this->model->getSize();
    double** results = new double*[modelSize];
    for (i = 0; i < modelSize; i += 1)
    {
        results[i] = new double[nGraphic];
    }
    return results;
}

void IntegratorBase::setParam(string name, double value)
{
    this->params[name] = value;
}

double IntegratorBase::getParam(string name)
{
    map<string, double> params = this->params;
    if (params.find(name) == params.end())
    {
        throw "Param " + name + " is not found";
    }
    else
    {
        return params[name];
    }
}

double *IntegratorBase::getTime()
{
    if (this->hGraphic == NULL)
    {
        throw "Perform intergation first";
    }

    int i;
    int nGraphic = this->nGraphic;
    double hGraphic = this->hGraphic;
    double t = this->tStart;
    double* time = new double[nGraphic];
    for (i = 0; i < nGraphic; i++)
    {
        time[i] = t;
        t += hGraphic;
    }
    return time;
}

void IntegratorBase::initIntegration()
{
    if (this->name.empty())
    {
        throw "Integrator name is not specified";
    }

    if (this->model == NULL)
    {
        throw "Model is not set";
    }

    if (this->x0 == NULL)
    {
        throw "Initial conditions aren't set";
    }

    if (this->eps == NULL)
    {
        throw "EPS is not set";
    }

    if (this->nGraphic == NULL)
    {
        throw "nGraphic is not set";
    }

    this->hGraphic = (this->tStop - this->tStart) / (double)this->nGraphic;
}
