#ifndef HAND_H
#define HAND_H

#define FINGER_COUNT 5

#define THUMB_FINGER_OFFSET -2.0
#define INDEX_FINGER_OFFSET -1.0
#define MIDDLE_FINGER_OFFSET 0.0
#define RING_FINGER_OFFSET 1.0
#define PINKY_FINGER_OFFSET 2.0

#define THUMB_FINGER_ROTATION -30
#define INDEX_FINGER_ROTATION -5
#define MIDDLE_FINGER_ROTATION 0.0
#define RING_FINGER_ROTATION 5
#define PINKY_FINGER_ROTATION 10

class Hand
{
protected:
    QVector<Finger> m_fingers;
public:
    Hand();

    QVector<QVector3D> GetJointPoints();
    QVector<int> GetFingertipValues();
    void SetFingerJoints(QVector<QVector<double>> p_JointAngles);
    void SetFingertipValues(QVector<int> p_FingertipValues);
};

#endif // HAND_H
