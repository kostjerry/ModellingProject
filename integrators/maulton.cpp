#include "maulton.h"

Maulton::Maulton()
{
    this->name = "Adams-Maulton (linear implicit 2-step method)";
}

double** Maulton::integrate()
{
    this->initIntegration();

    this->dMax = this->getParam("dMax");
    this->kMax = (int)this->getParam("kMax");
    this->dMin = this->dMax / 3.0;
    this->kMin = this->kMax / 3;

    Predictors *predictorsAlgo = new Predictors();
    Jacobi *jacobiAlgo = new Jacobi(eps);
    Gauss *gaussAlgo = new Gauss();
    ModelBase* model = this->model;
    int modelSize = model->getSize();
    double hInt = this->getFirstStepSize();
    double hPrev = hInt;
    double **x = this->getInitPoints(hInt);
    double t = this->tStart;
    double tStop = this->tStop;
    double tGraphic = hGraphic; // Time after which save graphic point is needed
    int iInt = 0; // Iteration index
    int nGraphic = this->nGraphic;
    int iGraphic = 1; // Index of current graphic point
    double hGraphic = this->hGraphic;
    double eps = this->eps;
    double** results = this->createResultsArray();
    double dMax = this->dMax;
    double dMin = this->dMin;
    int kMax = this->kMax;
    int kMin = this->kMin;

    // Save first point
    for (int i = 0; i < modelSize; i++)
    {
        results[i][0] = x0[i];
    }

    while (true)
    {
        double tp = t + hInt;
        double *xp = predictorsAlgo->linear(x, hPrev, hInt, modelSize);

        // Newton's corrector
        double *fNewton = new double[modelSize];
        int k = 0;
        bool reset = false;
        double dxMax = 0;
        while (true)
        {
            // Формула методу трапецій
            double *f1 = model->F(x[1], t);
            double *fp = model->F(xp, tp);
            for (int i = 0; i < modelSize; i++)
            {
                fNewton[i] = xp[i] - x[1][i] - 0.5 * hInt * (f1[i] + fp[i]);
            }

            // Рахуємо матрицю Якобі
            double **jacobi = jacobiAlgo->get(model, xp, tp);
            for (int i = 0; i < modelSize; i++)
            {
                for (int j = 0; j < modelSize; j++)
                {
                    jacobi[i][j] = ((i == j) ? 1.0 : 0.0) - 0.5 * hInt * jacobi[i][j];
                }
            }

            // Знаходимо вектор корекцій на k-тій ітерації і проводимо корекцію прогнозованого вектора
            double *dx = gaussAlgo->solve(jacobi, fNewton, modelSize);
            double dxAbs;
            dxMax = 0;
            for (int i = 0; i < modelSize; i++)
            {
                xp[i] -= dx[i];
                dxAbs = fabs(dx[i]);
                if (dxAbs > dxMax) dxMax = dxAbs;
            }

            k++;

            // Умова закінчення корекції прогнозованого значення
            if (dxMax < eps)
            {
                reset = false;
                break;
            }

            // Адаптивний алгоритм зміни поточного кроку інтегрування
            if ((k > kMax) || (dxMax > dMax))
            {
                reset = true;
                break;
            }
        }

        // Почати ітерацію заново з меншим кроком (адаптивний алгоритм)
        if (reset)
        {
            hInt *= 0.5;
            continue;
        }

        // Save changes
        x[0] = x[1];
        x[1] = xp;
        t = tp;
        iInt++;
        hPrev = hInt;

        // Break condition
        if (t >= tStop)
        {
            break;
        }

        // Save graphic point
        if ((t >= tGraphic) && (iGraphic < nGraphic))
        {
            for (int i = 0; i < modelSize; i++)
            {
                results[i][iGraphic] = x[0][i];
            }

            this->time[iGraphic] = tGraphic;
            tGraphic += hGraphic;
            iGraphic++;
        }

        // Пробуємо збільшувати крок, згідно з адаптивним алгоритмом
        if ((k <= kMin) && (dxMax <= dMin))
        {
            hInt *= 2.0;
            if (hInt > hGraphic)
            {
                hInt = hGraphic;
            }
        }
    }

    return results;
}

double Maulton::getFirstStepSize()
{
    double hInt = this->hGraphic;
    double dMax = this->dMax;
    int modelSize = this->model->getSize();

    // Знаходимо максимальний елемент вектора значень похідних в початковій точці
    double fMax = 0.0;
    double *derivative = this->model->F(this->x0, this->tStart);
    for (int i = 0; i < modelSize; i++)
    {
        double derTemp = fabs(derivative[i]);
        if (derTemp > fMax)
        {
            fMax = derTemp;
        }
    }

    // Знаходимо крок інтегрування
    while (true)
    {
        hInt *= 0.5;
        if (hInt * fMax < dMax)
        {
            hInt *= 2.0;
            break;
        }
    }

    return hInt;
}

double **Maulton::getInitPoints(double hInt)
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

