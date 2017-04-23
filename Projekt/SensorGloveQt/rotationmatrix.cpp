#include "includes.h"

RotationMatrix::RotationMatrix(char p_Axis, double p_Angle)
{
    p_Angle= p_Angle*M_PI/180;
    switch (p_Axis)
      {
      case 'x':
        {
        this->m_elements[0] = QVector3D(1,0,0);
        this->m_elements[1] = QVector3D(0, cos(p_Angle),-sin(p_Angle));
        this->m_elements[2] = QVector3D(0, sin(p_Angle), cos(p_Angle));
        } break;
      case 'y':
        {
        this->m_elements[0] = QVector3D(cos(p_Angle),  0, sin(p_Angle));
        this->m_elements[1] = QVector3D(0, 1, 0);
        this->m_elements[2] = QVector3D(-sin(p_Angle), 0, cos(p_Angle));
        } break;
      case 'z':
        {
        this->m_elements[0] = QVector3D(cos(p_Angle), -sin(p_Angle), 0);
        this->m_elements[1] = QVector3D(sin(p_Angle), cos(p_Angle),  0);
        this->m_elements[2] = QVector3D(0, 0, 1);
        } break;
      default:
        {
        this->m_elements[0] = QVector3D(1, 0, 0);
        this->m_elements[1] = QVector3D(0, 1, 0);
        this->m_elements[2] = QVector3D(0, 0, 1);
        }
      }
}
