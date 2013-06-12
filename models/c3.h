#ifndef C3_H
#define C3_H

#include <models/modelbase.h>

class C3 : public ModelBase
{
public:
    C3();
    double *F(double *x, double t);
};

#endif // C3_H
