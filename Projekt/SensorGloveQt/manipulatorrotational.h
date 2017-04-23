#ifndef MANIPULATORROTATIONAL_H
#define MANIPULATORROTATIONAL_H


class ManipulatorRotational
{
    QVector<Joint> m_joints;
    QVector3D m_position;
    double m_rotation;
public:
    ManipulatorRotational(QVector<Joint> p_joints,
                          QVector3D p_position=QVector3D(),
                          double p_rotation=double());

    void SetInternalCoordinates(QVector<double> p_angles);

    QVector3D GetPointInSystem(int p_point, int p_system=0);
    QVector<QVector3D> GetPointsInGlobal();
    QVector3D ForwardKinematics();
    void BackwardKinematics(QVector3D p_EffectorPosition);

};

#endif // MANIPULATORROTATIONAL_H
