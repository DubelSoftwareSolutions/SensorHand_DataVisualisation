#include "includes.h"

Hand::Hand(Qt3DCore::QEntity *p_rootEntity,QColor p_HandColor):m_rootEntity(p_rootEntity)
{
    Finger thumb(Finger::Thumb,
                 1.5, QVector3D(THUMB_FINGER_OFFSET,0,0),
                 THUMB_FINGER_ROTATION,m_rootEntity,p_HandColor);
    Finger index(Finger::IndexFinger,
                 1.5, QVector3D(INDEX_FINGER_OFFSET,0,0),
                 INDEX_FINGER_ROTATION,m_rootEntity,p_HandColor);
    Finger middle(Finger::MiddleFinger,
                  1.5, QVector3D(MIDDLE_FINGER_OFFSET,0,0),
                  MIDDLE_FINGER_ROTATION,m_rootEntity,p_HandColor);
    Finger ring(Finger::RingFinger,
                1.5, QVector3D(RING_FINGER_OFFSET,0,0),
                RING_FINGER_ROTATION,m_rootEntity,p_HandColor);
    Finger pinky(Finger::Pinky,
                 1.5, QVector3D(PINKY_FINGER_OFFSET,0,0),
                 PINKY_FINGER_ROTATION,m_rootEntity,p_HandColor);
    m_fingers.push_back(thumb);
    m_fingers.push_back(index);
    m_fingers.push_back(middle);
    m_fingers.push_back(ring);
    m_fingers.push_back(pinky);
}

QVector<QVector3D> Hand::GetJointPoints()
{/*
    QVector<QVector3D> jointPoints;

    for(Finger currentFinger : m_fingers)
        jointPoints.append(currentFinger.GetPointsInGlobal());

    return jointPoints;*/
    return QVector<QVector3D>();
}

QVector<int> Hand::GetFingertipValues()
{
    QVector<int> FingertipValues;

    for(Finger currentFinger : m_fingers)
        FingertipValues.push_back(currentFinger.GetFingertipValue());

    return FingertipValues;
}

void Hand::SetFingerJoints(QVector<QVector<double> > p_JointAngles)
{/*
    for(unsigned int i=0; i<FINGER_COUNT; ++i)
        m_fingers[i].SetInternalCoordinates(p_JointAngles[i]);*/
}

void Hand::SetFingertipValues(QVector<int> p_FingertipValues)
{
    for(unsigned int i=0; i<FINGER_COUNT; ++i)
        m_fingers[i].SetFingertipValue(p_FingertipValues[i]);
}
