#ifndef MANIPULATORROTATIONAL_H
#define MANIPULATORROTATIONAL_H

#include<QObject>
#include<Qt3DCore/QEntity>

#include"joint.h"

class ManipulatorRotational: public QObject
{
    Q_OBJECT
protected:
    Qt3DCore::QEntity *m_rootEntity;
    QVector<Joint*> m_joints;
    QVector3D m_position;
    float m_rotation;
public:
    ManipulatorRotational(QVector<Joint*> p_joints,
                          QVector3D p_position=QVector3D(),
                          float p_rotation=float(),
                          Qt3DCore::QEntity *p_rootEntity=nullptr);

    ManipulatorRotational(const ManipulatorRotational& p_manipulator);

    void TransformJointAngles(QVector<float> p_jointAngles);
    Joint *getLastJoint();
    virtual void SetInternalCoordinates(QVector<float> p_angles);

    QVector3D GetPointInSystem(int p_point, int p_system=0);
    QVector<QVector3D> GetPointsInGlobal();
    QVector3D ForwardKinematics();
};

#endif // MANIPULATORROTATIONAL_H
