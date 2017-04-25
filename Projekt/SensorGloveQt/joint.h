#ifndef JOINT_H
#define JOINT_H

class Joint
{
protected:
    double m_length;
    double m_angle;
public:
    Joint(double p_length=1, double p_angle=0);

    double length() const;
    double &angle();
    double angle() const;
};

#endif // JOINT_H
