#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <visual/gnuplot.h>
#include <models/spring.h>
#include <integrators/expliciteuler.h>
#include <iostream>
#include <math.h>
#include <QMessageBox>
#include <integrators/impliciteuler.h>
#include <algorithms/eigenvalues.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    try
    {
        double **ttt = new double*[2];
        ttt[0] = new double[2];
        ttt[1] = new double[2];
        Eigenvalues *e = new Eigenvalues(ttt, 2);
        e->getMin();

        return;

        int nGraphic = 800;
        double* x0 = new double[2];
        x0[0] = 1.0;
        x0[1] = 2.0;
        Spring* spring = new Spring();
        IntegratorBase *euler = new ImplicitEuler();
        euler->setModel(spring);
        euler->setNGraphic(nGraphic);
        euler->setX0(x0);
        euler->setTStart(0.0);
        euler->setTStop(1.0);
        euler->setEps(0.001);
        euler->setParam("hInt", 0.001);
        double** results = euler->integrate();
        double* time = euler->getTime();

        Gnuplot *plot = new Gnuplot();
        plot->addGraphicView(0, 1, "X");
        plot->addGraphicView(0, 2, "Y");
        plot->addGraphicView(1, 2, "Phase");
        plot->plotGraphics(results, time, nGraphic);
    }
    catch (const char* e)
    {
        QMessageBox::information(NULL, "Error", e, QMessageBox::Ok);
    }
    catch (string e)
    {
        QMessageBox::information(NULL, "Error", e.c_str(), QMessageBox::Ok);
    }
}
