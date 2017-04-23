#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H 

#define M_PI 3.14159265358979323846

class RotationMatrix: public QMatrix3x3
{
public:
    RotationMatrix();
    RotationMatrix(char p_Axis, double p_Angle);
    RotationMatrix(const float* p_values);

    QVector3D operator *(const QVector3D & p_Vector3D);
};

#endif // ROTATIONMATRIX_H
