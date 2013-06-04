#ifndef S4A_H
#define S4A_H

#include <models/modelbase.h>

class S4a : public ModelBase
{
public:
    S4a();
    double *F(double *x, double t);
};

#endif // S4A_H
