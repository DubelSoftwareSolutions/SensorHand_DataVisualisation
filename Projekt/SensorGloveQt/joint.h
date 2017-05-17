#ifndef JOINT_H
#define JOINT_H

#define CYLINDER_RINGS_COUNT 100
#define CYLINDER_SLICES_COUNT 20
#include<QObject>
#include<Qt3DCore/QEntity>
#include<Qt3DCore/QTransform>
#include<QMatrix4x4>
#include<QColor>

class Joint: public QObject
{
    Q_OBJECT
protected:
    float m_radius;
    float m_length;
    float m_angle;
    float m_tilt;
    float m_rotation;
    QVector3D m_position;
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_CylinderEntity;
    Qt3DCore::QTransform *m_CylinderTransform;
    QMatrix4x4 m_TransformMatrix;

public:
    Joint(Qt3DCore::QEntity *p_rootEntity=nullptr,
          float p_radius=1,float p_length=1, float p_angle=0, float p_tilt=0, float p_rotation=0, QVector3D p_position=QVector3D(),
          Joint *p_PrevJoint=nullptr,
          QColor p_color=QColor(255,173,96));
    Joint(const Joint& p_joint);

    float length() const;
    float &length();
    float angle() const;
    QMatrix4x4 TransformMatrix() const;
    void TransformAngle(float p_newAngle, Joint *p_PrevJoint=nullptr);

    Joint &operator = (const Joint& p_joint);
};

#endif // JOINT_H
