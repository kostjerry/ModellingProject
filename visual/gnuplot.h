#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <map>
#include <utility>
#include <string>

using namespace std;

typedef pair<int, int> int_pair;

class Gnuplot
{
public:
    Gnuplot();
    void plotGraphics(double **data, double *time, int n);
    void plotGraphic(double *x, double *y, int n, string name);
    void addGraphicView(int coord1, int coord2, string name);
    void clearGraphicViews();
private:
    map<string, int_pair> graphicViews;
};

#endif // GNUPLOT_H
