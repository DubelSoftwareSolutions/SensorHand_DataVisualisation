#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <cmath>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QScreen>

#include <QObject>
#include <QVector3D>
#include <QMatrix3x3>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QtGlobal>
#include <QDataStream>
#include <QtBluetooth>
#include <QtSerialPort>

#include <QGuiApplication>

#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>

#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>
#include <Qt3DRender/qpointlight.h>
#include <Qt3DRender/qrenderaspect.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DInput/qinputaspect.h>

#include <Qt3DExtras/qforwardrenderer.h>
#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>

#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>

#include "errorhandler.h"
#include "rotationmatrix.h"
#include "joint.h"
#include "manipulatorrotational.h"
#include "fingertip.h"
#include "finger.h"
#include "hand.h"
#include "scene.h"
#include "input.h"

#endif // INCLUDES_H
