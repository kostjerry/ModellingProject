#include "stiffness.h"
#include "eigenvalues.h"

Stiffness::Stiffness()
{
}

double Stiffness::get(double **jacobi, int n)
{
    Eigenvalues *eigenvalues = new Eigenvalues(jacobi, n);
    double max, min;
    int maxIterationsCount, minIterationsCount;

    max = eigenvalues->getMax();
    maxIterationsCount = eigenvalues->getIterationsCount();
    min = eigenvalues->getMin();
    minIterationsCount = eigenvalues->getIterationsCount();
    this->iterationsCount = maxIterationsCount + minIterationsCount;
    this->value = fabs(max / ((n == 1) ? 1.0 : min));

    return this->value;
}

double Stiffness::getPM(double **jacobi, int n)
{
    ExactMethodBase *pm = new PowerMethod(jacobi, n);
    double max, min;
    int maxIterationsCount, minIterationsCount;

    max = pm->getMax();
    maxIterationsCount = pm->getIterationsCount();
    min = pm->getMin();
    minIterationsCount = pm->getIterationsCount();
    this->iterationsCount = maxIterationsCount + minIterationsCount;
    this->value = fabs(max / ((n == 1) ? 1.0 : min));

    return this->value;
}

double Stiffness::getSPM(double **jacobi, int n)
{
    ExactMethodBase *pm = new SPM(jacobi, n);
    double max, min;
    int maxIterationsCount, minIterationsCount;

    max = pm->getMax();
    maxIterationsCount = pm->getIterationsCount();
    min = pm->getMin();
    minIterationsCount = pm->getIterationsCount();
    this->iterationsCount = maxIterationsCount + minIterationsCount;
    this->value = fabs(max / ((n == 1) ? 1.0 : min));

    return this->value;
}

double Stiffness::getIPM(double **jacobi, int n)
{
    ExactMethodBase *pm = new IPM(jacobi, n);
    double max, min;
    int maxIterationsCount, minIterationsCount;

    max = pm->getMax();
    maxIterationsCount = pm->getIterationsCount();
    min = pm->getMin();
    minIterationsCount = pm->getIterationsCount();
    this->iterationsCount = maxIterationsCount + minIterationsCount;
    this->value = fabs(max / ((n == 1) ? 1.0 : min));

    return this->value;
}

int Stiffness::getIterationsCount()
{
    return this->iterationsCount;
}

double Stiffness::getValue()
{
    return this->value;
}
