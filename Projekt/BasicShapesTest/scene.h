#ifndef SCENE_H
#define SCENE_H

#include <QtCore/QObject>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QConeMesh>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>

class Scene : public QObject
{
    Q_OBJECT

private:
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_Cylinder1Entity;
    Qt3DCore::QEntity *m_Cylinder2Entity;
    Qt3DCore::QEntity *m_Cylinder3Entity;

    Qt3DCore::QEntity *m_Cylinder1Entity2;
    Qt3DCore::QEntity *m_Cylinder2Entity2;
    Qt3DCore::QEntity *m_Cylinder3Entity2;
public:
    explicit Scene(Qt3DCore::QEntity *rootEntity);
    ~Scene();

    void EnableCylinders();
signals:

public slots:
};

#endif // SCENE_H
