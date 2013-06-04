#ifndef S27D_H
#define S27D_H

#include <models/modelbase.h>

class S27d : public ModelBase
{
public:
    S27d();
    double *F(double *x, double t);
};

#endif // S27D_H
