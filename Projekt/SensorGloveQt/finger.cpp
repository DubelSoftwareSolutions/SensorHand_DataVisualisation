#include "includes.h"

Finger::Finger(FingerType_t p_fingerType,
               int p_fingertipValue,
               QVector3D p_position,
               double p_rotation,
               Qt3DCore::QEntity *p_rootEntity,
               QColor p_fingerColor):
    m_fingertipValue(p_fingertipValue),m_rootEntity(p_rootEntity)
{
    QVector<Joint*> joints;
    switch(p_fingerType)
    {
    case Thumb:
    {
        Joint *joint0=new Joint(FINGER_RADIUS,THUMB_JOINT0_LENGTH,0,p_rotation,-60,p_position,nullptr,m_rootEntity,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(FINGER_RADIUS,THUMB_JOINT1_LENGTH,30,p_rotation,-60,p_position,joint0,m_rootEntity,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(FINGER_RADIUS,THUMB_JOINT2_LENGTH,30,p_rotation,-60,p_position,joint1,m_rootEntity,p_fingerColor);
        joints.push_back(joint2);
        m_manipulator= new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    case IndexFinger:
    {
        Joint *joint0=new Joint(FINGER_RADIUS,INDEX_FINGER_JOINT0_LENGTH,0,p_rotation,0,p_position,nullptr,m_rootEntity,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(FINGER_RADIUS,INDEX_FINGER_JOINT1_LENGTH,30,p_rotation,0,p_position,joint0,m_rootEntity,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(FINGER_RADIUS,INDEX_FINGER_JOINT2_LENGTH,30,p_rotation,0,p_position,joint1,m_rootEntity,p_fingerColor);
        joints.push_back(joint2);
        Joint *joint3=new Joint(FINGER_RADIUS,INDEX_FINGER_JOINT3_LENGTH,30,p_rotation,0,p_position,joint2,m_rootEntity,p_fingerColor);
        joints.push_back(joint3);
        m_manipulator=new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    case MiddleFinger:
    {
        Joint *joint0=new Joint(FINGER_RADIUS,MIDDLE_FINGER_JOINT0_LENGTH,0,p_rotation,0,p_position,nullptr,m_rootEntity,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(FINGER_RADIUS,MIDDLE_FINGER_JOINT1_LENGTH,30,p_rotation,0,p_position,joint0,m_rootEntity,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(FINGER_RADIUS,MIDDLE_FINGER_JOINT2_LENGTH,30,p_rotation,0,p_position,joint1,m_rootEntity,p_fingerColor);
        joints.push_back(joint2);
        Joint *joint3=new Joint(FINGER_RADIUS,MIDDLE_FINGER_JOINT3_LENGTH,30,p_rotation,0,p_position,joint2,m_rootEntity,p_fingerColor);
        joints.push_back(joint3);
        m_manipulator=new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    case RingFinger:
    {
        Joint *joint0=new Joint(FINGER_RADIUS,RING_FINGER_JOINT0_LENGTH,0,p_rotation,0,p_position,nullptr,m_rootEntity,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(FINGER_RADIUS,RING_FINGER_JOINT1_LENGTH,30,p_rotation,0,p_position,joint0,m_rootEntity,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(FINGER_RADIUS,RING_FINGER_JOINT2_LENGTH,30,p_rotation,0,p_position,joint1,m_rootEntity,p_fingerColor);
        joints.push_back(joint2);
        Joint *joint3=new Joint(FINGER_RADIUS,RING_FINGER_JOINT3_LENGTH,30,p_rotation,0,p_position,joint2,m_rootEntity,p_fingerColor);
        joints.push_back(joint3);
        m_manipulator=new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    case Pinky:
    {
        Joint *joint0=new Joint(FINGER_RADIUS,PINKY_JOINT0_LENGTH,0,p_rotation,0,p_position,nullptr,m_rootEntity,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(FINGER_RADIUS,PINKY_JOINT1_LENGTH,30,p_rotation,0,p_position,joint0,m_rootEntity,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(FINGER_RADIUS,PINKY_JOINT2_LENGTH,30,p_rotation,0,p_position,joint1,m_rootEntity,p_fingerColor);
        joints.push_back(joint2);
        Joint *joint3=new Joint(FINGER_RADIUS,PINKY_JOINT3_LENGTH,30,p_rotation,0,p_position,joint2,m_rootEntity,p_fingerColor);
        joints.push_back(joint3);
        m_manipulator=new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    }
}

Finger::Finger(const Finger &p_finger)
{
    m_fingertipValue = p_finger.m_fingertipValue;
    m_rootEntity = p_finger.m_rootEntity;
    m_manipulator = p_finger.m_manipulator;
}

Finger &Finger::operator =(const Finger &p_finger)
{
    m_fingertipValue = p_finger.m_fingertipValue;
    m_rootEntity = p_finger.m_rootEntity;
    m_manipulator = p_finger.m_manipulator;
    return *this;
}

void Finger::SetInternalCoordinates(QVector<double> p_angles)
{
    /*for(int i=0;i<m_joints.size()-1 && i<p_angles.size();++i)
    {
        if(p_angles[i]<0)
            throw (ErrorHandler::ErrorType_t::NegativeAngle);
        m_joints[i].angle()=p_angles[i];
    }*/
}

int Finger::GetFingertipValue() const
{
    return m_fingertipValue;
}

void Finger::SetFingertipValue(int p_NewFingertipValue)
{
    m_fingertipValue = p_NewFingertipValue;
}
