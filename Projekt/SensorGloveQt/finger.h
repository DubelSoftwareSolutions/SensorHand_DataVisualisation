#ifndef FINGER_H
#define FINGER_H

#define FINGER_JOINTS_COUNT 4

#define THUMB_JOINT0_LENGTH 7.0
#define THUMB_JOINT1_LENGTH 3.0
#define THUMB_JOINT2_LENGTH 3.0

#define INDEX_FINGER_JOINT0_LENGTH 8.5
#define INDEX_FINGER_JOINT1_LENGTH 5.0
#define INDEX_FINGER_JOINT2_LENGTH 2.5
#define INDEX_FINGER_JOINT3_LENGTH 2.0

#define MIDDLE_FINGER_JOINT0_LENGTH 8.0
#define MIDDLE_FINGER_JOINT1_LENGTH 5.3
#define MIDDLE_FINGER_JOINT2_LENGTH 2.8
#define MIDDLE_FINGER_JOINT3_LENGTH 2.3

#define RING_FINGER_JOINT0_LENGTH 7.5
#define RING_FINGER_JOINT1_LENGTH 4.5
#define RING_FINGER_JOINT2_LENGTH 2.8
#define RING_FINGER_JOINT3_LENGTH 2.4

#define PINKY_JOINT0_LENGTH 6.3
#define PINKY_JOINT1_LENGTH 3.3
#define PINKY_JOINT2_LENGTH 2.0
#define PINKY_JOINT3_LENGTH 2.3

class Finger : public ManipulatorRotational
{
protected:
    int m_fingertipValue;
public:

    enum FingerType_t {Thumb,IndexFinger,MiddleFinger,RingFinger,Pinky};

    Finger(FingerType_t p_fingerType = IndexFinger,
           int p_fingertipValue=0,
           QVector3D p_position=QVector3D(),
           double p_rotation=double());


    void SetInternalCoordinates(QVector<double> p_angles);
    int GetFingertipValue() const;
    void SetFingertipValue(int p_NewFingertipValue);
};

#endif // FINGER_H
