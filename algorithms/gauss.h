#ifndef GAUSS_H
#define GAUSS_H

#include <math.h>

using namespace std;

class Gauss
{
public:
    Gauss();
    double* solve(double** a, double* b, int n);
private:
    double eps;
};

#endif // GAUSS_H
