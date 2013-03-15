#include "expliciteuler.h"

ExplicitEuler::ExplicitEuler()
{
    this->name = "Explicit Euler";
}

double** ExplicitEuler::integrate()
{
    this->initIntegration();

    ModelBase* model = this->model;
    int modelSize = model->getSize();
    double** results = this->createResultsArray();
    double t = this->tStart;
    double tStop = this->tStop;
    int nGraphic = this->nGraphic;
    int iGraphic = 1; // Index of current graphic point
    double hGraphic = this->hGraphic;
    double tGraphic = hGraphic; // Time after which save graphic point is needed
    double hInt = this->getParam("hInt");
    int iInt = 0; // Iteration index
    double* f;
    int i;

    // Init history container
    double** x = new double*[2];
    x[0] = new double[modelSize];
    x[1] = new double[modelSize];

    // Save 1st point
    for (i = 0; i < modelSize; i++)
    {
        results[i][0] = x0[i];
        x[0][i] = x0[i];
    }

    while (true)
    {
        // Explicit Euler formula
        f = model->F(x[0], t);
        for (i = 0; i < modelSize; i++)
        {
            x[1][i] = x[0][i] + hInt * f[i];
        }

        // Save changes
        x[0] = x[1];

        // Increment time
        t += hInt;
        iInt++;

        // Test break condition
        if (t >= tStop)
            break;

        // Save graphic point
        if ((t >= tGraphic) && (iGraphic < nGraphic))
        {
            for (i = 0; i < modelSize; i++)
            {
                results[i][iGraphic] = x[0][i];
            }
            tGraphic += hGraphic;
            iGraphic++;
        }
    }

    return results;
}
