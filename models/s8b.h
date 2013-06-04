#ifndef S8B_H
#define S8B_H

#include <models/modelbase.h>

class S8b : public ModelBase
{
public:
    S8b();
    double *F(double *x, double t);
};

#endif // S8B_H
