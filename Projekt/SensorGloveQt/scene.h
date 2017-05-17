#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "mainwindow.h"
#include "joint.h"
#include "finger.h"
#include "hand.h"

class Scene : public QObject
{
    Q_OBJECT
private:
    Qt3DCore::QEntity *m_rootEntity;
    Hand m_Hand3DModel;

    Qt3DExtras::Qt3DWindow *view;
    QWidget *container;
    QSize screenSize;
    QWidget *widget;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    Qt3DInput::QInputAspect *input;
    Qt3DRender::QCamera *cameraEntity;
    Qt3DExtras::QFirstPersonCameraController *camController;
    Qt3DCore::QEntity *lightEntity;
    Qt3DRender::QPointLight *light;
    Qt3DCore::QTransform *lightTransform;
    Qt3DCore::QEntity *lightEntity2;
    Qt3DRender::QPointLight *light2;
    Qt3DCore::QTransform *lightTransform2;

public:
    explicit Scene(Qt3DCore::QEntity *rootEntity, MainWindow& p_mainWindow);
    ~Scene();

    void SetHandTransformation(QVector<QVector<float>> p_FingerAngles);
    void SetHandFingertipValues(QVector<int> p_NewValues);
signals:

public slots:
};

#endif // SCENE_H
