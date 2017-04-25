#include "includes.h"

Finger::Finger(QVector3D p_position,
               double p_rotation,
               int p_fingertipValue,
               FingerType_t p_fingerType):
    ManipulatorRotational(QVector<Joint>(FINGER_JOINTS_COUNT),p_position,p_rotation),
    m_fingertipValue(p_fingertipValue)
{
    switch(p_fingerType)
    {
    case Thumb:
        m_joints.pop_back();
        m_joints[0] = THUMB_JOINT0_LENGTH;
        m_joints[1] = THUMB_JOINT1_LENGTH;
        m_joints[2] = THUMB_JOINT2_LENGTH;
        break;
    case IndexFinger:
        m_joints[0] = INDEX_FINGER_JOINT0_LENGTH;
        m_joints[1] = INDEX_FINGER_JOINT1_LENGTH;
        m_joints[2] = INDEX_FINGER_JOINT2_LENGTH;
        m_joints[3] = INDEX_FINGER_JOINT3_LENGTH;
        break;
    case MiddleFinger:
        m_joints[0] = MIDDLE_FINGER_JOINT0_LENGTH;
        m_joints[1] = MIDDLE_FINGER_JOINT1_LENGTH;
        m_joints[2] = MIDDLE_FINGER_JOINT2_LENGTH;
        m_joints[3] = MIDDLE_FINGER_JOINT3_LENGTH;
        break;
    case RingFinger:
        m_joints[0] = RING_FINGER_JOINT0_LENGTH;
        m_joints[1] = RING_FINGER_JOINT1_LENGTH;
        m_joints[2] = RING_FINGER_JOINT2_LENGTH;
        m_joints[3] = RING_FINGER_JOINT3_LENGTH;
        break;
    case Pinky:
        m_joints[0] = PINKY_JOINT0_LENGTH;
        m_joints[1] = PINKY_JOINT1_LENGTH;
        m_joints[2] = PINKY_JOINT2_LENGTH;
        m_joints[3] = PINKY_JOINT3_LENGTH;
        break;
    }
}

void Finger::SetInternalCoordinates(QVector<double> p_angles)
{
    for(int i=0;i<m_joints.size()-1 && i<p_angles.size();++i)
    {
        if(p_angles[i]<0)
            throw (ErrorHandler::ErrorType_t::NegativeAngle);
        m_joints[i].angle()=p_angles[i];
    }
}

int Finger::GetFingertipValue() const
{
    return m_fingertipValue;
}

void Finger::SetFingertipValue(int p_NewFingertipValue)
{
    m_fingertipValue = p_NewFingertipValue;
}
