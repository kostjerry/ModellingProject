#-------------------------------------------------
#
# Project created by QtCreator 2013-02-21T17:15:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Modelling
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    visual/gnuplot.cpp \
    models/modelbase.cpp \
    integrators/integratorbase.cpp \
    models/spring.cpp \
    integrators/expliciteuler.cpp \
    algorithms/gauss.cpp \
    algorithms/jacobi.cpp \
    integrators/impliciteuler.cpp \
    algorithms/predictors.cpp \
    tools/matrix.cpp \
    tools/vector.cpp \
    algorithms/stiffness.cpp \
    algorithms/eigenvalues.cpp \
    tools/complex.cpp \
    algorithms/eigenvalues/exact/powermethod.cpp \
    algorithms/eigenvalues/exact/inversepowermethod.cpp \
    algorithms/eigenvalues/estimate/estimatemethodbase.cpp \
    algorithms/eigenvalues/exact/exactmethodbase.cpp \
    algorithms/eigenvalues/estimate/gershgorinmethod.cpp \
    algorithms/eigenvalues/estimate/normmethod.cpp \
    models/stiff.cpp \
    models/stiff2.cpp \
    algorithms/eigenvalues/exact/spm.cpp \
    models/s4a.cpp \
    models/s8b.cpp \
    models/s19c.cpp \
    models/s27d.cpp \
    models/s28e.cpp \
    algorithms/op.cpp \
    algorithms/eigenvalues/exact/ipm.cpp \
    integrators/shichman.cpp \
    integrators/maulton.cpp \
    integrators/fdn.cpp

HEADERS  += mainwindow.h \
    visual/gnuplot.h \
    models/modelbase.h \
    integrators/integratorbase.h \
    models/spring.h \
    integrators/expliciteuler.h \
    algorithms/gauss.h \
    algorithms/jacobi.h \
    integrators/impliciteuler.h \
    algorithms/predictors.h \
    tools/matrix.h \
    tools/vector.h \
    algorithms/stiffness.h \
    algorithms/eigenvalues.h \
    tools/complex.h \
    algorithms/eigenvalues/exact/powermethod.h \
    algorithms/eigenvalues/exact/inversepowermethod.h \
    algorithms/eigenvalues/estimate/estimatemethodbase.h \
    algorithms/eigenvalues/exact/exactmethodbase.h \
    algorithms/eigenvalues/estimate/gershgorinmethod.h \
    algorithms/eigenvalues/estimate/normmethod.h \
    models/stiff.h \
    models/stiff2.h \
    algorithms/eigenvalues/exact/spm.h \
    models/s4a.h \
    models/s8b.h \
    models/s19c.h \
    models/s27d.h \
    models/s28e.h \
    algorithms/op.h \
    algorithms/eigenvalues/exact/ipm.h \
    integrators/shichman.h \
    integrators/maulton.h \
    integrators/fdn.h

FORMS    += mainwindow.ui
