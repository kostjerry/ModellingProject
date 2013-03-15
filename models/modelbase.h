#ifndef MODELBASE_H
#define MODELBASE_H

#include <string>

using namespace std;

class ModelBase
{
public:
    ModelBase();
    virtual double* F(double* x, double t);
    int getSize();
protected:
    string name;
    int size;
};

#endif // MODELBASE_H
