#include "gnuplot.h"
#include <stdio.h>

Gnuplot::Gnuplot()
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
}

void Gnuplot::plotGraphics(double** data, double* time, int n)
{
    map<string, int_pair> graphicsView = this->graphicViews;
    map<string, int_pair>::iterator iter;
    for (iter = graphicsView.begin(); iter != graphicsView.end(); ++iter)
    {
        string name = iter->first;
        int_pair p = iter->second;
        int indexFirst = p.first;
        double *x;
        if (indexFirst == 0)
        {
            x = time;
        }
        else
        {
            x = data[indexFirst - 1];
        }
        double *y = data[p.second - 1];
        this->plotGraphic(x, y, n, name);
    }
}

void Gnuplot::plotGraphic(double *x, double *y, int n, string name)
{
    FILE* gp = popen("gnuplot -persistent", "w");
    fprintf(gp, "plot '-' using 1:2 with line title '%s'\n", name.c_str());
    for (int i = 0; i < n; i++)
    {
        fprintf(gp, "%f\t%f\n", x[i], y[i]);
    }
    fprintf(gp, "e\n");
    fclose(gp);
}

void Gnuplot::addGraphicView(int coord1, int coord2, string name)
{
    int_pair graphicView(coord1, coord2);
    this->graphicViews[name] = graphicView;
}

void Gnuplot::clearGraphicViews()
{
    this->graphicViews.clear();
}
