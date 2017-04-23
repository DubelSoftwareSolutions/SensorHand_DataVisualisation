#include "includes.h"

Joint::Joint(double p_length,double p_angle):
    m_length(p_length),m_angle(p_angle)
{

}

double Joint::length() const
{
    return m_length;
}

double &Joint::angle()
{
    return m_angle;
}

double Joint::angle() const
{
    return m_angle;
}
