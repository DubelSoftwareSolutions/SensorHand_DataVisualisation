#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H 

class RotationMatrix: public QMatrix3x3
{
    RotationMatrix(const float* p_values);
public:
    RotationMatrix();
    RotationMatrix(float p_Angle, char p_Axis);

    QVector3D operator *(const QVector3D & p_Vector3D);
};

#endif // ROTATIONMATRIX_H
