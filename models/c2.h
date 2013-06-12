#ifndef C2_H
#define C2_H

#include <models/modelbase.h>

class C2 : public ModelBase
{
public:
    C2();
    double *F(double *x, double t);
};

#endif // C2_H
