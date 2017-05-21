#ifndef SCENE_H
#define SCENE_H

/*!
 * \file
 * \brief Definicja klasy Scene
 *
 * Plik zawiera definicję klasy Scene, która
 * jest klasą pochodną klasy QObject
 */

#include <QObject>
#include <Qt3DCore>
#include <Qt3DExtras>
#include <Qt3DRender>
#include <QHBoxLayout>
#include <QVBoxLayout>
//#include "mainwindow.h"
#include "joint.h"
#include "finger.h"
#include "hand.h"

/*!
 * \brief Modeluje pojecie sceny z elementami 3D
 *
 * Inicjuje trójwymiatowy model ręki zdefioniowany klasą Hand,
 * za pomocą biblioteki Qt3D, a także inicjalizuje widok, widget,
 * rozmiar okna, układ, wejście danych, kontroler perspektywy i oświetlenie
 */
class Scene : public QObject
{
    Q_OBJECT
private:


public:
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

    //explicit Scene(Qt3DCore::QEntity *rootEntity, MainWindow& p_mainWindow);
    explicit Scene(Qt3DCore::QEntity *rootEntity);
    ~Scene();

    void SetHandTransformation(QVector<QVector<float>> p_FingerAngles);
    void SetHandFingertipValues(QVector<int> p_NewValues);
signals:

public slots:
};

#endif // SCENE_H
