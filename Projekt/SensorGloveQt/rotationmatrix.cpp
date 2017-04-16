#include "includes.h"

RotationMatrix::RotationMatrix(char p_Axis, double p_Angle):m_elements(ROTATION_MATRIX_DIMENSIONS)
{
    p_Angle= p_Angle*M_PI/180;
    switch (p_Axis)
      {
      case 'x':
        {
        this->m_elements[0] = EuclideanVector(1,0,0);
        this->m_elements[1] = EuclideanVector(0, cos(p_Angle),-sin(p_Angle));
        this->m_elements[2] = EuclideanVector(0, sin(p_Angle), cos(p_Angle));
        } break;
      case 'y':
        {
        this->m_elements[0] = EuclideanVector(cos(p_Angle),  0, sin(p_Angle));
        this->m_elements[1] = EuclideanVector(0, 1, 0);
        this->m_elements[2] = EuclideanVector(-sin(p_Angle), 0, cos(p_Angle));
        } break;
      case 'z':
        {
        this->m_elements[0] = EuclideanVector(cos(p_Angle), -sin(p_Angle), 0);
        this->m_elements[1] = EuclideanVector(sin(p_Angle), cos(p_Angle),  0);
        this->m_elements[2] = EuclideanVector(0, 0, 1);
        } break;
      default:
        {
        this->m_elements[0] = EuclideanVector(1, 0, 0);
        this->m_elements[1] = EuclideanVector(0, 1, 0);
        this->m_elements[2] = EuclideanVector(0, 0, 1);
        }
      }
}
