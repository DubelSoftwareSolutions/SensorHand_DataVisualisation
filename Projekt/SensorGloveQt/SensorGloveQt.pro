#-------------------------------------------------
#
# Project created by QtCreator 2017-04-16T17:21:49
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += 3dcore 3drender 3dinput 3dextras
QT       += datavisualization
QT       += bluetooth
QT       += serialport
QT       += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SensorGloveQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    joint.cpp \
    manipulatorrotational.cpp \
    finger.cpp \
    errorhandler.cpp \
    hand.cpp \
    input.cpp \
    scene.cpp \
    fingertip.cpp \
    chart.cpp \
    chartwindow.cpp

HEADERS  += mainwindow.h \
    includes.h \
    joint.h \
    manipulatorrotational.h \
    finger.h \
    errorhandler.h \
    hand.h \
    input.h \
    scene.h \
    fingertip.h \
    chart.h \
    chartwindow.h

FORMS    += mainwindow.ui \
    chartwindow.ui
