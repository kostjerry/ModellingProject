#ifndef STIFF2_H
#define STIFF2_H

#include <models/modelbase.h>

class Stiff2 : public ModelBase
{
public:
    Stiff2();
    double* F(double *x, double t);
};

#endif // STIFF2_H
