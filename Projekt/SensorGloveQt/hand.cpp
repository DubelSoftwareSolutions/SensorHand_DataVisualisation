#include "includes.h"

Hand::Hand()
{
    Finger thumb(Finger::Thumb,0,
                          QVector3D(0,THUMB_FINGER_OFFSET,0),THUMB_FINGER_ROTATION);
    Finger index(Finger::IndexFinger,0,
                          QVector3D(0,INDEX_FINGER_OFFSET,0),INDEX_FINGER_ROTATION);
    Finger middle(Finger::MiddleFinger,0,
                           QVector3D(0,MIDDLE_FINGER_OFFSET,0),MIDDLE_FINGER_ROTATION);
    Finger ring(Finger::RingFinger,0,
                         QVector3D(0,RING_FINGER_OFFSET,0),RING_FINGER_ROTATION);
    Finger pinky(Finger::Pinky,0,
                          QVector3D(0,PINKY_FINGER_OFFSET,0),PINKY_FINGER_ROTATION);
    m_fingers.push_back(thumb);
    m_fingers.push_back(index);
    m_fingers.push_back(middle);
    m_fingers.push_back(ring);
    m_fingers.push_back(pinky);
}

QVector<QVector3D> Hand::GetJointPoints()
{
    QVector<QVector3D> jointPoints;

    for(Finger currentFinger : m_fingers)
        jointPoints.append(currentFinger.GetPointsInGlobal());

    return jointPoints;
}

QVector<int> Hand::GetFingertipValues()
{
    QVector<int> FingertipValues;

    for(Finger currentFinger : m_fingers)
        FingertipValues.push_back(currentFinger.GetFingertipValue());

    return FingertipValues;
}

void Hand::SetFingerJoints(QVector<QVector<double> > p_JointAngles)
{
    for(unsigned int i=0; i<FINGER_COUNT; ++i)
        m_fingers[i].SetInternalCoordinates(p_JointAngles[i]);
}

void Hand::SetFingertipValues(QVector<int> p_FingertipValues)
{
    for(unsigned int i=0; i<FINGER_COUNT; ++i)
        m_fingers[i].SetFingertipValue(p_FingertipValues[i]);
}
