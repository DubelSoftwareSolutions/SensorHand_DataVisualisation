#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H

class RotationMatrix: public QMatrix3x3
{
public:
    RotationMatrix(char p_Axis, double p_Angle);
};

#endif // ROTATIONMATRIX_H
