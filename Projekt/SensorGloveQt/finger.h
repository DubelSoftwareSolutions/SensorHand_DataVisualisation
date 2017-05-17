#ifndef FINGER_H
#define FINGER_H

#define FINGER_JOINTS_COUNT 4
#define FINGER_RADIUS 1

#define THUMB_JOINT_COUNT 2
#define THUMB_JOINT0_LENGTH 7.0f
#define THUMB_JOINT1_LENGTH 3.0f
#define THUMB_JOINT2_LENGTH 3.0f

#define INDEX_JOINT_COUNT 3
#define INDEX_FINGER_JOINT0_LENGTH 8.5f
#define INDEX_FINGER_JOINT1_LENGTH 5.0f
#define INDEX_FINGER_JOINT2_LENGTH 2.5f
#define INDEX_FINGER_JOINT3_LENGTH 2.0f

#define MIDDLE_JOINT_COUNT 3
#define MIDDLE_FINGER_JOINT0_LENGTH 8.0f
#define MIDDLE_FINGER_JOINT1_LENGTH 5.3f
#define MIDDLE_FINGER_JOINT2_LENGTH 2.8f
#define MIDDLE_FINGER_JOINT3_LENGTH 2.3f

#define RING_JOINT_COUNT 3
#define RING_FINGER_JOINT0_LENGTH 7.5f
#define RING_FINGER_JOINT1_LENGTH 4.5f
#define RING_FINGER_JOINT2_LENGTH 2.8f
#define RING_FINGER_JOINT3_LENGTH 2.4f

#define PINKY_JOINT_COUNT 3
#define PINKY_JOINT0_LENGTH 6.3f
#define PINKY_JOINT1_LENGTH 3.3f
#define PINKY_JOINT2_LENGTH 2.0f
#define PINKY_JOINT3_LENGTH 2.3f

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
           QVector3D p_position=QVector3D(),
           float p_rotation=float(),
           QColor p_fingerColor=QColor(255,173,96));

    Finger(const Finger& p_finger);
    Finger &operator = (const Finger& p_finger);

    void TransformJointAngles(QVector<float> p_angles);

    int GetFingertipValue() const;
    void SetFingertipValue(int p_NewFingertipValue);
};

#endif // FINGER_H
