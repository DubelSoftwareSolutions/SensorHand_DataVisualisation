#include "includes.h"

RotationMatrix::RotationMatrix():QGenericMatrix()
{

}

RotationMatrix::RotationMatrix(char p_Axis, double p_Angle)
{
    p_Angle= p_Angle*M_PI/180;
    switch (p_Axis)
      {
      case 'x':
        {
        float Values[9]={1,0,0,
                         0,cos(p_Angle),-sin(p_Angle),
                         0, sin(p_Angle), cos(p_Angle)};
        *this=RotationMatrix(Values);
        } break;
      case 'y':
        {
        float Values[9]={cos(p_Angle), 0, sin(p_Angle),
                         0, 1, 0,
                         -sin(p_Angle), 0, cos(p_Angle)};
        *this=RotationMatrix(Values);
        } break;
      case 'z':
        {
        float Values[9]={cos(p_Angle), -sin(p_Angle), 0,
                         sin(p_Angle), cos(p_Angle),  0,
                         0, 0, 1};
        *this=RotationMatrix(Values);
        } break;
      default:
        {
        RotationMatrix();
        }
    }
}

RotationMatrix::RotationMatrix(const float *p_values):QGenericMatrix(p_values)
{

}
