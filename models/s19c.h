#ifndef S19C_H
#define S19C_H

#include <models/modelbase.h>

class S19c : public ModelBase
{
public:
    S19c();
    double *F(double *x, double t);
};

#endif // S19C_H
