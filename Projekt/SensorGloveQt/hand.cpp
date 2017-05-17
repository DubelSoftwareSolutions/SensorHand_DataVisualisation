#include "includes.h"

Hand::Hand(Qt3DCore::QEntity *p_rootEntity,QColor p_HandColor):m_rootEntity(p_rootEntity)
{
    Finger thumb(m_rootEntity,Finger::Thumb,
                 QVector3D(THUMB_FINGER_OFFSET,0,0),
                 THUMB_FINGER_ROTATION,p_HandColor);
    Finger index(m_rootEntity,Finger::IndexFinger,
                 QVector3D(INDEX_FINGER_OFFSET,0,0),
                 INDEX_FINGER_ROTATION,p_HandColor);
    Finger middle(m_rootEntity,Finger::MiddleFinger,
                  QVector3D(MIDDLE_FINGER_OFFSET,0,0),
                  MIDDLE_FINGER_ROTATION,p_HandColor);
    Finger ring(m_rootEntity,Finger::RingFinger,
                QVector3D(RING_FINGER_OFFSET,0,0),
                RING_FINGER_ROTATION,p_HandColor);
    Finger pinky(m_rootEntity,Finger::Pinky,
                 QVector3D(PINKY_FINGER_OFFSET,0,0),
                 PINKY_FINGER_ROTATION,p_HandColor);
    m_fingers.push_back(thumb);
    m_fingers.push_back(index);
    m_fingers.push_back(middle);
    m_fingers.push_back(ring);
    m_fingers.push_back(pinky);
}

void Hand::TransformFingerAngles(QVector<QVector<float> > p_FingerAngles)
{
    for(int i=0; i<m_fingers.size(); ++i)
    {
        m_fingers[i].TransformJointAngles(p_FingerAngles[i]);
        m_fingers[i].TransformFingertipPosition();
    }
}

QVector<QVector3D> Hand::GetJointPoints()
{/*
    QVector<QVector3D> jointPoints;

    for(Finger currentFinger : m_fingers)
        jointPoints.append(currentFinger.GetPointsInGlobal());

    return jointPoints;*/
    return QVector<QVector3D>();
}

QVector<float> Hand::GetFingertipValues() const
{
    QVector<float> FingertipValues;

    for(Finger currentFinger : m_fingers)
        FingertipValues.push_back(currentFinger.GetFingertipValue());

    return FingertipValues;
}

void Hand::SetFingerJoints(QVector<QVector<float> > p_JointAngles)
{/*
    for(unsigned int i=0; i<FINGER_COUNT; ++i)
        m_fingers[i].SetInternalCoordinates(p_JointAngles[i]);*/
}

void Hand::SetFingertipValues(QVector<int> p_FingertipValues)
{
    for(int i=0; i<FINGER_COUNT && i<p_FingertipValues.size(); ++i)
        m_fingers[i].SetFingertipValue(p_FingertipValues[i]);
}
