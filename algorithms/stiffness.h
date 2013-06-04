#ifndef STIFFNESS_H
#define STIFFNESS_H

class Stiffness
{
private:
    int iterationsCount;
    double value;
public:
    Stiffness();
    double get(double **jacobi, int n);
    int getIterationsCount();
    double getValue();
    double getPM(double **jacobi, int n);
    double getSPM(double **jacobi, int n);
    double getIPM(double **jacobi, int n);
};

#endif // STIFFNESS_H
