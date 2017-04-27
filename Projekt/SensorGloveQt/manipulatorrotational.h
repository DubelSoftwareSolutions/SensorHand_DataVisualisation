#ifndef MANIPULATORROTATIONAL_H
#define MANIPULATORROTATIONAL_H


class ManipulatorRotational
{
protected:
    QVector<Joint> m_joints;
    QVector3D m_position;
    double m_rotation;
public:
    ManipulatorRotational(QVector<Joint> p_joints,
                          QVector3D p_position=QVector3D(),
                          double p_rotation=double());

    virtual void SetInternalCoordinates(QVector<double> p_angles);

    QVector3D GetPointInSystem(int p_point, int p_system=0);
    QVector<QVector3D> GetPointsInGlobal();
    QVector3D ForwardKinematics();
};

#endif // MANIPULATORROTATIONAL_H
