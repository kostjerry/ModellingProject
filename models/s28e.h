#ifndef S28E_H
#define S28E_H

#include <models/modelbase.h>

class S28e : public ModelBase
{
public:
    S28e();
    double *F(double *x, double t);
};

#endif // S28E_H
