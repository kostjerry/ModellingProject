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
    algorithms/predictors.cpp

HEADERS  += mainwindow.h \
    visual/gnuplot.h \
    models/modelbase.h \
    integrators/integratorbase.h \
    models/spring.h \
    integrators/expliciteuler.h \
    algorithms/gauss.h \
    algorithms/jacobi.h \
    integrators/impliciteuler.h \
    algorithms/predictors.h

FORMS    += mainwindow.ui
