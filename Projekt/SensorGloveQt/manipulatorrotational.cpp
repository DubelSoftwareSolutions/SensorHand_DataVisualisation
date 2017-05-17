#include "includes.h"


ManipulatorRotational::ManipulatorRotational(QVector<Joint*> p_joints, QVector3D p_position, float p_rotation,Qt3DCore::QEntity *p_rootEntity):
    m_joints(p_joints),m_position(p_position),m_rotation(p_rotation),m_rootEntity(p_rootEntity)
{
}

ManipulatorRotational::ManipulatorRotational(const ManipulatorRotational &p_manipulator)
{
    m_rootEntity = p_manipulator.m_rootEntity;
    m_joints = p_manipulator.m_joints;
    m_position = p_manipulator.m_position;
    m_rotation = p_manipulator.m_rotation;
}

void ManipulatorRotational::TransformJointAngles(QVector<float> p_jointAngles)
{
    int i;
    for(i=1; i<m_joints.size() && i-1<p_jointAngles.size(); ++i)
        m_joints[i]->TransformAngle(p_jointAngles[i-1],m_joints[i-1]);
    for(;i<m_joints.size();++i)
        m_joints[i]->TransformAngle(m_joints[i]->angle(),m_joints[i-1]);
}

Joint *ManipulatorRotational::getLastJoint()
{
    return m_joints.last();
}
