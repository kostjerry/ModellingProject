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
    void setX0(double *x0);
    void setTStart(double tStart);
    void setTStop(double tStop);
    double *getX0();
    double getTStart();
    double getTStop();
protected:
    string name;
    int size;
    double* x0;
    double tStart;
    double tStop;
};

#endif // MODELBASE_H
