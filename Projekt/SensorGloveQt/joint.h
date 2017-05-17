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
    double m_radius;
    double m_length;
    double m_angle;
    double m_tilt;
    double m_rotation;
    QVector3D m_position;
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_CylinderEntity;
    Qt3DCore::QTransform *m_CylinderTransform;
    QMatrix4x4 m_TransformMatrix;

public:
    Joint(Qt3DCore::QEntity *p_rootEntity=nullptr,
          double p_radius=1,double p_length=1, double p_angle=0, double p_tilt=0, double p_rotation=0, QVector3D p_position=QVector3D(),
          Joint *p_PrevJoint=nullptr,
          QColor p_color=QColor(255,173,96));
    Joint(const Joint& p_joint);

    double length() const;
    double &length();
    double angle() const;
    QMatrix4x4 TransformMatrix() const;
    void TransformAngle(double p_newAngle, Joint *p_PrevJoint=nullptr);

    Joint &operator = (const Joint& p_joint);
};

#endif // JOINT_H
