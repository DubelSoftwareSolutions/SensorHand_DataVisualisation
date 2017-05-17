#ifndef FINGERTIP_H
#define FINGERTIP_H

#include <QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPhongMaterial>
#include <QMatrix4x4>

#include "joint.h"

#define SPHERE_RADIUS 1.5
#define SPHERE_RINGS_COUNT 20
#define SPHERE_SLICES_COUNT 20
#define SPHERE_SCALE 0.05

class Fingertip : public QObject
{
    Q_OBJECT
protected:
    int m_fingertipValue;
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_sphereEntity;
    Qt3DCore::QTransform *m_sphereTransform;
    Qt3DExtras::QPhongMaterial *m_sphereMaterial;
    QMatrix4x4 m_TransformMatrix;
public:
    explicit Fingertip(Qt3DCore::QEntity *p_rootEntity=nullptr,
                       Joint *p_PrevJoint=nullptr,
                       int p_fingertipValue = int());

    void TransformFingertip(Joint *p_prevJoint);
    void setFingertipValue(int p_newValue);
    float getFingertipValue() const;
signals:

public slots:
};

#endif // FINGERTIP_H
