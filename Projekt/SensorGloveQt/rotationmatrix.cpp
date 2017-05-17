#include "includes.h"

RotationMatrix::RotationMatrix():QGenericMatrix()
{

}

RotationMatrix::RotationMatrix(float p_Angle, char p_Axis)
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

QVector3D RotationMatrix::operator *(const QVector3D &p_Vector3D)
{
    QVector3D OutputVector;
    const float *MatrixData=this->constData();
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
            OutputVector[j]+=p_Vector3D[i]*MatrixData[i*3+j];
    }
    return OutputVector;
}


