#include "includes.h"

Finger::Finger(Qt3DCore::QEntity *p_rootEntity, FingerType_t p_fingerType,
               QVector3D p_position,
               float p_rotation,
               QColor p_fingerColor):
    m_rootEntity(p_rootEntity),m_fingerType(p_fingerType)
{

    QVector<Joint*> joints;
    switch(p_fingerType)
    {
    case Thumb:
    {
        Joint *joint0=new Joint(m_rootEntity,FINGER_RADIUS,THUMB_JOINT0_LENGTH,0,p_rotation,-60,p_position,nullptr,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(m_rootEntity,FINGER_RADIUS,THUMB_JOINT1_LENGTH,30,p_rotation,-60,p_position,joint0,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(m_rootEntity,FINGER_RADIUS,THUMB_JOINT2_LENGTH,30,p_rotation,-60,p_position,joint1,p_fingerColor);
        joints.push_back(joint2);
        m_manipulator= new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    case IndexFinger:
    {
        Joint *joint0=new Joint(m_rootEntity,FINGER_RADIUS,INDEX_FINGER_JOINT0_LENGTH,0,p_rotation,0,p_position,nullptr,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(m_rootEntity,FINGER_RADIUS,INDEX_FINGER_JOINT1_LENGTH,30,p_rotation,0,p_position,joint0,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(m_rootEntity,FINGER_RADIUS,INDEX_FINGER_JOINT2_LENGTH,30,p_rotation,0,p_position,joint1,p_fingerColor);
        joints.push_back(joint2);
        Joint *joint3=new Joint(m_rootEntity,FINGER_RADIUS,INDEX_FINGER_JOINT3_LENGTH,30,p_rotation,0,p_position,joint2,p_fingerColor);
        joints.push_back(joint3);
        m_manipulator=new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    case MiddleFinger:
    {
        Joint *joint0=new Joint(m_rootEntity,FINGER_RADIUS,MIDDLE_FINGER_JOINT0_LENGTH,0,p_rotation,0,p_position,nullptr,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(m_rootEntity,FINGER_RADIUS,MIDDLE_FINGER_JOINT1_LENGTH,30,p_rotation,0,p_position,joint0,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(m_rootEntity,FINGER_RADIUS,MIDDLE_FINGER_JOINT2_LENGTH,30,p_rotation,0,p_position,joint1,p_fingerColor);
        joints.push_back(joint2);
        Joint *joint3=new Joint(m_rootEntity,FINGER_RADIUS,MIDDLE_FINGER_JOINT3_LENGTH,30,p_rotation,0,p_position,joint2,p_fingerColor);
        joints.push_back(joint3);
        m_manipulator=new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    case RingFinger:
    {
        Joint *joint0=new Joint(m_rootEntity,FINGER_RADIUS,RING_FINGER_JOINT0_LENGTH,0,p_rotation,0,p_position,nullptr,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(m_rootEntity,FINGER_RADIUS,RING_FINGER_JOINT1_LENGTH,30,p_rotation,0,p_position,joint0,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(m_rootEntity,FINGER_RADIUS,RING_FINGER_JOINT2_LENGTH,30,p_rotation,0,p_position,joint1,p_fingerColor);
        joints.push_back(joint2);
        Joint *joint3=new Joint(m_rootEntity,FINGER_RADIUS,RING_FINGER_JOINT3_LENGTH,30,p_rotation,0,p_position,joint2,p_fingerColor);
        joints.push_back(joint3);
        m_manipulator=new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    case Pinky:
    {
        Joint *joint0=new Joint(m_rootEntity,FINGER_RADIUS,PINKY_JOINT0_LENGTH,0,p_rotation,0,p_position,nullptr,p_fingerColor);
        joints.push_back(joint0);
        Joint *joint1=new Joint(m_rootEntity,FINGER_RADIUS,PINKY_JOINT1_LENGTH,30,p_rotation,0,p_position,joint0,p_fingerColor);
        joints.push_back(joint1);
        Joint *joint2=new Joint(m_rootEntity,FINGER_RADIUS,PINKY_JOINT2_LENGTH,30,p_rotation,0,p_position,joint1,p_fingerColor);
        joints.push_back(joint2);
        Joint *joint3=new Joint(m_rootEntity,FINGER_RADIUS,PINKY_JOINT3_LENGTH,30,p_rotation,0,p_position,joint2,p_fingerColor);
        joints.push_back(joint3);
        m_manipulator=new ManipulatorRotational(joints,p_position,p_rotation);
    }
        break;
    }
    m_fingertip = new Fingertip(m_rootEntity,joints.last());
}

Finger::Finger(const Finger &p_finger)
{
    m_fingertip = p_finger.m_fingertip;
    m_rootEntity = p_finger.m_rootEntity;
    m_manipulator = p_finger.m_manipulator;
    m_fingerType = p_finger.m_fingerType;
}

Finger &Finger::operator =(const Finger &p_finger)
{
    m_fingertip = p_finger.m_fingertip;
    m_rootEntity = p_finger.m_rootEntity;
    m_manipulator = p_finger.m_manipulator;
    m_fingerType = p_finger.m_fingerType;
    return *this;
}

void Finger::TransformJointAngles(QVector<float> p_angles)
{
    int FingerJointCount;
    switch(m_fingerType)
    {
    case Thumb:
    {
        FingerJointCount = THUMB_JOINT_COUNT;
        m_manipulator->setRotation(-p_angles[0]);
        p_angles.erase(p_angles.begin());
    } break;
    default:
    {
        FingerJointCount = INDEX_JOINT_COUNT;
    } break;
    }
    m_manipulator->TransformJointAngles(p_angles);
    m_fingertip->TransformFingertip(m_manipulator->getLastJoint());
}

int Finger::GetFingertipValue() const
{
    return m_fingertip->getFingertipValue();
}

void Finger::SetFingertipValue(int p_NewFingertipValue)
{
    m_fingertip->setFingertipValue(p_NewFingertipValue);
}
