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

void ManipulatorRotational::SetInternalCoordinates(QVector<float> p_angles)
{/*
    for(int i=0;i<m_joints.size()-1;++i)
        m_joints[i].angle()=p_angles[i];*/
}

QVector3D ManipulatorRotational::GetPointInSystem(int p_point, int p_system)
{/*
    if(p_point==p_system)
        return QVector3D();
    else
    {
        RotationMatrix Matrix(m_joints[p_system].angle(),'y');
        return Matrix*
                (this->GetPointInSystem(p_point,p_system+1)+
                 QVector3D(m_joints[p_point].length(),0,0));
    }*/
    return QVector3D();
}

QVector<QVector3D> ManipulatorRotational::GetPointsInGlobal()
{/*
    QVector<QVector3D> OutputPoints;
    QVector3D TempVector;
    for(int i=0;i<m_joints.size();++i)
    {
        TempVector=m_position+ (RotationMatrix(m_rotation,'z') * GetPointInSystem(i));
        OutputPoints.push_back(TempVector);
    }
    return OutputPoints;*/
    return QVector<QVector3D>();
}

QVector3D ManipulatorRotational::ForwardKinematics()
{/*
    return m_position+ (RotationMatrix(m_rotation,'z') * GetPointInSystem(m_joints.size()));
*/
    return QVector3D();
}
