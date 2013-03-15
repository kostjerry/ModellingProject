#ifndef EXPLICITEULER_H
#define EXPLICITEULER_H

#include <integrators/integratorbase.h>
#include <iostream>

using namespace std;

class ExplicitEuler : public IntegratorBase
{
public:
    ExplicitEuler();
    double** integrate();
};

#endif // EXPLICITEULER_H
