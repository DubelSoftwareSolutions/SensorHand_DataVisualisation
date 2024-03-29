#include "scene.h"
#include <QApplication>

#include <QGuiApplication>

#include <Qt3DRender/qcamera.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcameralens.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtGui/QScreen>

#include <Qt3DInput/QInputAspect>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>
#include <Qt3DRender/qpointlight.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DExtras/qforwardrenderer.h>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(12,175,189));
    QWidget *container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200,100));
    container->setMaximumSize(screenSize);

    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);
    hLayout->addWidget(container,1);
    hLayout->addLayout(vLayout);

    widget->setWindowTitle(QString("QBasic Shapes Test"));

    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
    view->registerAspect(input);

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    //Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();
    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0,0,20));
    cameraEntity->setUpVector(QVector3D(0,1,0));
    cameraEntity->setViewCenter(QVector3D(0,0,0));

    //Light
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor(QColor("white"));
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    //Light
    Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light2 = new Qt3DRender::QPointLight(lightEntity2);
    light2->setColor(QColor("white"));
    light2->setIntensity(1);
    lightEntity2->addComponent(light2);
    Qt3DCore::QTransform *lightTransform2 = new Qt3DCore::QTransform(lightEntity2);
    lightTransform2->setTranslation(QVector3D(0,0,-20));
    lightEntity2->addComponent(lightTransform2);


    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    Scene *scene3D = new Scene(rootEntity);
    view->setRootEntity(rootEntity);

    scene3D->EnableCylinders();

    widget->show();
    widget->resize(1200,800);

    return app.exec();
}
