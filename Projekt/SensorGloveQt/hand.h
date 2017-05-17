#ifndef HAND_H
#define HAND_H

#define FINGER_COUNT 5

#define THUMB_FINGER_OFFSET 2.0
#define INDEX_FINGER_OFFSET 1.0
#define MIDDLE_FINGER_OFFSET 0.0
#define RING_FINGER_OFFSET -1.0
#define PINKY_FINGER_OFFSET -2.0

#define THUMB_FINGER_ROTATION -30
#define INDEX_FINGER_ROTATION -10
#define MIDDLE_FINGER_ROTATION 0.0
#define RING_FINGER_ROTATION 10
#define PINKY_FINGER_ROTATION 20

#include<QObject>
#include<Qt3DCore/QEntity>

#include"joint.h"
#include"manipulatorrotational.h"
#include"fingertip.h"
#include"finger.h"

class Hand: public QObject
{
    Q_OBJECT
protected:
    Qt3DCore::QEntity *m_rootEntity;
    QVector<Finger> m_fingers;
public:
    Hand(Qt3DCore::QEntity *p_rootEntity = nullptr,QColor p_HandColor = QColor(255,173,96));

    QVector<int> GetFingertipValues() const;
    void SetFingerJoints(QVector<QVector<float>> p_JointAngles);
    void SetFingertipValues(QVector<int> p_FingertipValues);
};

#endif // HAND_H
