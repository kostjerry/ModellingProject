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
#include <models/stiff.h>
#include <models/stiff2.h>
#include <models/s4a.h>
#include <models/s8b.h>
#include <models/s19c.h>
#include <models/s27d.h>
#include <models/s28e.h>
#include <integrators/shichman.h>
#include <integrators/maulton.h>

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
/*
        double **tt = new double*[2];
        tt[0] = new double[2];
        tt[1] = new double[2];
        tt[0][0] = 1.0;
        tt[0][1] = 0.0;
        tt[1][0] = 0.0;
        tt[1][1] = -1.0;

        double **ttt = new double*[3];
        ttt[0] = new double[3];
        ttt[1] = new double[3];
        ttt[2] = new double[3];
        ttt[0][0] = 1.0;
        ttt[0][1] = 2.0;
        ttt[0][2] = 3.0;
        ttt[1][0] = 4.0;
        ttt[1][1] = 5.0;
        ttt[1][2] = 6.0;
        ttt[2][0] = 7.0;
        ttt[2][1] = 8.0;
        ttt[2][2] = 9.0;

        ExactMethodBase *e = new PowerMethod(ttt, 3);
        cout << "Min = " << e->getMin() << endl;
        cout << "Iterations = " << e->getIterationsCount() << endl;
        cout << "Max = " << e->getMax() << endl;
        cout << "Iterations = " << e->getIterationsCount() << endl;

        return;
*/


        int nGraphic = 800;
        ModelBase* model = new Spring();
        IntegratorBase *intergator = new Maulton();
        intergator->setModel(model);
        intergator->setNGraphic(nGraphic);
        intergator->setEps(0.001);
        intergator->setParam("hInt", (model->getTStop() - model->getTStart()) / (double)nGraphic);
        intergator->setParam("dMax", 0.01);
        intergator->setParam("kMax", 11);

        double** results = intergator->integrate();
        double* time = intergator->getTime();
        //double* stiffnessPM = euler->stiffnessPM;
        //double* stiffnessPMIterations = euler->stiffnessPMIterations;
        //double* stiffnessSPM = euler->stiffnessSPM;
        //double* stiffnessSPMIterations = euler->stiffnessSPMIterations;
        //double* stiffnessIPM = euler->stiffnessIPM;
        //double* stiffnessIPMIterations = euler->stiffnessIPMIterations;

        Gnuplot *plot = new Gnuplot();
        plot->plotGraphic(time, results[0], nGraphic, "X");
        plot->plotGraphic(time, results[1], nGraphic, "Y");

        //plot->plotGraphic(time, stiffnessPM, nGraphic, "Stiffness PM");
        //plot->plotGraphic(time, stiffnessPMIterations, nGraphic, "StiffnessPMIterations");
        //plot->plotGraphic(time, stiffnessSPM, nGraphic, "Stiffness SPM");
        //plot->plotGraphic(time, stiffnessSPMIterations, nGraphic, "StiffnessSPMIterations");
        //plot->plotGraphic(time, stiffnessIPM, nGraphic, "Stiffness IPM");
        //plot->plotGraphic(time, stiffnessIPMIterations, nGraphic, "StiffnessIPMIterations");
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
