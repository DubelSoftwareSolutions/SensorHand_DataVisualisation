#include "includes.h"


ManipulatorRotational::ManipulatorRotational(QVector<Joint> p_joints, QVector3D p_position, double p_rotation):
    m_joints(p_joints),m_position(p_position),m_rotation(p_rotation)
{
}

QVector3D ManipulatorRotational::GetPointInSystem(int p_point, int p_system)
{
    if(p_point==p_system)
        return QVector3D();
    else
        return QVector3D();
        /*return RotationMatrix(m_joints[p_system].angle(),'y')*
                (this->GetPointInSystem(p_point,p_system+1)+
                 QVector3D(m_joints[p_system].length()));*/

}

QVector<QVector3D> ManipulatorRotational::GetPointsInGlobal()
{
    QVector<QVector3D> OutputPoints;
    QVector3D TempVector;
    for(int i=0;i<m_joints.size()+1;++i)
    {
        TempVector=m_position+ (RotationMatrix(m_rotation,'z') * GetPointInSystem(i));
        OutputPoints.push_back(TempVector);
    }
    return OutputPoints;
}

QVector3D ManipulatorRotational::ForwardKinematics()
{
    return m_position+ (RotationMatrix(m_rotation,'z') * GetPointInSystem(m_joints.size()));
}

void ManipulatorRotational::BackwardKinematics(QVector3D p_EffectorPosition)
{

}
