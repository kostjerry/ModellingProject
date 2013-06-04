#ifndef STIFF_H
#define STIFF_H

#include <models/modelbase.h>

class Stiff : public ModelBase
{
public:
    Stiff();
    double* F(double *x, double t);
};

#endif // STIFF_H
