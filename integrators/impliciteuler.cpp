#include "impliciteuler.h"
#include <algorithms/eigenvalues.h>
#include <algorithms/stiffness.h>
#include <algorithms/op.h>

ImplicitEuler::ImplicitEuler()
{
    this->name = "Implicit Euler";
}

double** ImplicitEuler::integrate()
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
    double eps = this->eps;
    int i, j;
    double *fNewton,
           **jacobi,
           **jacobiSave,
           *dx,
           dxMax,
           dxAbs,
           *xp, // predicted vector
           *fp, // F of predicted vector
           tp, // predicted time
           stiffnessVal,
           eMin, eMax; // eigenvalues vars
    double **x = this->getInitPoints(hInt); // History container
    Predictors *predictorsAlgo = new Predictors();
    Jacobi *jacobiAlgo = new Jacobi(eps);
    Gauss *gaussAlgo = new Gauss();
    Stiffness *stiffAlgo = new Stiffness();
    Op *op = new Op();
    jacobiSave = op->createMatrix(modelSize);

    // Save 1st point
    for (i = 0; i < modelSize; i++)
    {
        results[i][0] = x0[i];
    }

    while (true)
    {
        tp = t + hInt;
        xp = predictorsAlgo->linear(x, hInt, hInt, modelSize);

        // Newton's corrector
        fNewton = new double[modelSize];
        while (true)
        {
            // Implicit Euler formula
            fp = model->F(xp, tp);
            for (i = 0; i < modelSize; i++)
            {
                fNewton[i] = xp[i] - x[1][i] - hInt * fp[i];
            }

            // Calculate Jacobi matrix
            jacobi = jacobiAlgo->get(model, xp, tp);
            op->copyMatrix(jacobiSave, jacobi, modelSize);

            for (i = 0; i < modelSize; i++)
            {
                for (j = 0; j < modelSize; j++)
                {
                    jacobi[i][j] = ((i == j) ? 1.0 : 0.0) - hInt * jacobi[i][j];
                }
            }

            // Find corrections
            dx = gaussAlgo->solve(jacobi, fNewton, modelSize);
            dxMax = 0;
            for (i = 0; i < modelSize; i++)
            {
                xp[i] -= dx[i];
                dxAbs = fabs(dx[i]);
                if (dxAbs > dxMax) dxMax = dxAbs;
            }

            // Break condition
            if (dxMax < eps)
            {
                break;
            }
        }

        // Save changes
        x[0] = x[1];
        x[1] = xp;
        t = tp;
        iInt++;

        // Break condition
        if (t >= tStop)
        {
            break;
        }

        // Save graphic point
        if ((t >= tGraphic) && (iGraphic < nGraphic))
        {
            for (i = 0; i < modelSize; i++)
            {
                results[i][iGraphic] = x[0][i];
            }

            this->stiffnessPM[iGraphic] = stiffAlgo->getPM(jacobiSave, modelSize);
            this->stiffnessPMIterations[iGraphic] = stiffAlgo->getIterationsCount();

            this->stiffnessSPM[iGraphic] = stiffAlgo->getSPM(jacobiSave, modelSize);
            this->stiffnessSPMIterations[iGraphic] = stiffAlgo->getIterationsCount();

            this->stiffnessIPM[iGraphic] = stiffAlgo->getIPM(jacobiSave, modelSize);
            this->stiffnessIPMIterations[iGraphic] = stiffAlgo->getIterationsCount();

            this->time[iGraphic] = tGraphic;
            tGraphic += hGraphic;
            iGraphic++;
        }
    }

    return results;
}

double **ImplicitEuler::getInitPoints(double hInt)
{
    int i;
    int modelSize = this->model->getSize();
    double **x = new double*[2];
    x[0] = new double[modelSize];
    x[1] = this->x0;
    double *f = this->model->F(x[1], this->tStart);
    for (i = 0; i < modelSize; i++)
    {
        // Back step by using Explicit Euler
        x[0][i] = x[1][i] - hInt * f[i];
    }
    return x;
}
