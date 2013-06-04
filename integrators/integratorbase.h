#ifndef INTEGRATORBASE_H
#define INTEGRATORBASE_H

#include <models/modelbase.h>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

class IntegratorBase
{
public:
    IntegratorBase();
    virtual double** integrate();
    void setModel(ModelBase*);
    void setX0(double*);
    void setTStart(double);
    void setTStop(double);
    void setEps(double);
    void setNGraphic(int);
    void setParam(string name, double value);
    double getParam(string name);
    double* getTime();

    double *stiffnessPM = NULL;
    double *stiffnessPMIterations = NULL;
    double *stiffnessSPM = NULL;
    double *stiffnessSPMIterations = NULL;
    double *stiffnessIPM = NULL;
    double *stiffnessIPMIterations = NULL;
protected:
    string name = "";
    ModelBase* model = NULL;
    double* x0 = NULL;
    double tStart = 0.0;
    double tStop = 1.0;
    double eps = NULL;
    int nGraphic = NULL;
    double hGraphic = NULL;
    double** createResultsArray();
    double *time = NULL;
    void initIntegration();
private:
    map<string, double> params;
};

#endif // INTEGRATORBASE_H
