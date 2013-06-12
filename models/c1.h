#ifndef C1_H
#define C1_H

#include <models/modelbase.h>

class C1 : public ModelBase
{
public:
    C1();
    double *F(double *x, double t);
};

#endif // C1_H
