#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H 

class RotationMatrix: public QMatrix3x3
{
public:
    RotationMatrix();
    RotationMatrix(double p_Angle, char p_Axis);
    RotationMatrix(const float* p_values);

    QVector3D operator *(const QVector3D & p_Vector3D);
};

#endif // ROTATIONMATRIX_H
