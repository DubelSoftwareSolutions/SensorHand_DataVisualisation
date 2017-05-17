#ifndef FINGER_H
#define FINGER_H

#define FINGER_JOINTS_COUNT 4
#define FINGER_RADIUS 1

#define THUMB_JOINT_COUNT 2
#define THUMB_JOINT0_LENGTH 7.0
#define THUMB_JOINT1_LENGTH 3.0
#define THUMB_JOINT2_LENGTH 3.0

#define INDEX_JOINT_COUNT 3
#define INDEX_FINGER_JOINT0_LENGTH 8.5
#define INDEX_FINGER_JOINT1_LENGTH 5.0
#define INDEX_FINGER_JOINT2_LENGTH 2.5
#define INDEX_FINGER_JOINT3_LENGTH 2.0

#define MIDDLE_JOINT_COUNT 3
#define MIDDLE_FINGER_JOINT0_LENGTH 8.0
#define MIDDLE_FINGER_JOINT1_LENGTH 5.3
#define MIDDLE_FINGER_JOINT2_LENGTH 2.8
#define MIDDLE_FINGER_JOINT3_LENGTH 2.3

#define RING_JOINT_COUNT 3
#define RING_FINGER_JOINT0_LENGTH 7.5
#define RING_FINGER_JOINT1_LENGTH 4.5
#define RING_FINGER_JOINT2_LENGTH 2.8
#define RING_FINGER_JOINT3_LENGTH 2.4

#define PINKY_JOINT_COUNT 3
#define PINKY_JOINT0_LENGTH 6.3
#define PINKY_JOINT1_LENGTH 3.3
#define PINKY_JOINT2_LENGTH 2.0
#define PINKY_JOINT3_LENGTH 2.3

#include<QObject>
#include<Qt3DCore/QEntity>
#include<QMatrix4x4>
#include<QColor>

#include"joint.h"
#include"manipulatorrotational.h"
#include"fingertip.h"

class Finger : public QObject
{
    Q_OBJECT
public:
    enum FingerType_t {Thumb,IndexFinger,MiddleFinger,RingFinger,Pinky};
protected:
    Fingertip *m_fingertip;

    Qt3DCore::QEntity *m_rootEntity;
    ManipulatorRotational *m_manipulator;

    FingerType_t m_fingerType;
public:
    Finger(Qt3DCore::QEntity *p_rootEntity=nullptr,
           FingerType_t p_fingerType = IndexFinger,
           float p_fingertipValue=0,
           QVector3D p_position=QVector3D(),
           double p_rotation=double(),
           QColor p_fingerColor=QColor(255,173,96));

    Finger(const Finger& p_finger);
    Finger &operator = (const Finger& p_finger);

    void TransformJointAngles(QVector<double> p_angles);
    void TransformFingertipPosition();

    void SetInternalCoordinates(QVector<double> p_angles);
    float GetFingertipValue() const;
    void SetFingertipValue(int p_NewFingertipValue);
};

#endif // FINGER_H
