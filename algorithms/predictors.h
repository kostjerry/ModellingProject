#ifndef PREDICTORS_H
#define PREDICTORS_H

class Predictors
{
public:
    Predictors();
    double *linear(double **history, double hPrev, double hNext, int modelSize);
};

#endif // PREDICTORS_H
