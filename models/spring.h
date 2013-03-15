#ifndef SPRING_H
#define SPRING_H

#include <models/modelbase.h>

class Spring : public ModelBase
{
public:
    Spring();
    double* F(double *x, double t);
};

#endif // SPRING_H
