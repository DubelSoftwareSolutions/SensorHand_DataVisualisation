#include "includes.h"

Joint::Joint(double p_radius,double p_length,double p_angle, double p_tilt, double p_rotation, QVector3D p_position,
             Joint *p_PrevJoint,
             Qt3DCore::QEntity *p_rootEntity,QColor p_color):
    m_radius(p_radius),m_length(p_length),m_angle(p_angle),m_tilt(p_tilt),m_position(p_position),
    m_rootEntity(p_rootEntity)
{
    Qt3DExtras::QCylinderMesh *cylinderMesh = new Qt3DExtras::QCylinderMesh();
    cylinderMesh->setRadius(m_radius);
    cylinderMesh->setLength(m_length);
    cylinderMesh->setRings(CYLINDER_RINGS_COUNT);
    cylinderMesh->setSlices(CYLINDER_SLICES_COUNT);

    Qt3DExtras::QPhongMaterial *cylinderMaterial = new Qt3DExtras::QPhongMaterial();
    cylinderMaterial->setDiffuse(p_color);

    Qt3DCore::QTransform *cylinderTransform = new Qt3DCore::QTransform();
    cylinderTransform->setScale(1);

    if(p_PrevJoint == nullptr)
    {
        m_TransformMatrix = QMatrix4x4();
        m_TransformMatrix.translate(p_position);
        m_TransformMatrix.rotate(-p_rotation/2,QVector3D(1,0,0));
        m_TransformMatrix.rotate(p_tilt,QVector3D(0,0,1));
        m_TransformMatrix.rotate(p_rotation,QVector3D(0,1,0));

    }
    else
    {
        m_TransformMatrix = p_PrevJoint->m_TransformMatrix;
        m_TransformMatrix.translate(0,p_PrevJoint->length()/2);
    }
    m_TransformMatrix.rotate(p_angle,QVector3D(1,0,0));
    m_TransformMatrix.translate(QVector3D(0,m_length/2,0));

    cylinderTransform->setMatrix(m_TransformMatrix);

    m_CylinderEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_CylinderEntity->addComponent(cylinderMesh);
    m_CylinderEntity->addComponent(cylinderMaterial);
    m_CylinderEntity->addComponent(cylinderTransform);
}

Joint::Joint(const Joint &p_joint)
{
    m_radius = p_joint.m_radius;
    m_length = p_joint.m_length;
    m_angle = p_joint.m_angle;
    m_rootEntity = p_joint.m_rootEntity;
    m_CylinderEntity = p_joint.m_CylinderEntity;
}

double Joint::length() const
{
    return m_length;
}

double &Joint::length()
{
    return m_length;
}

double &Joint::angle()
{
    return m_angle;
}

double Joint::angle() const
{
    return m_angle;
}

Joint &Joint::operator =(const Joint &p_joint)
{
    m_radius = p_joint.m_radius;
    m_length = p_joint.m_length;
    m_angle = p_joint.m_angle;
    m_rootEntity = p_joint.m_rootEntity;
    m_CylinderEntity = p_joint.m_CylinderEntity;
    return *this;
}
