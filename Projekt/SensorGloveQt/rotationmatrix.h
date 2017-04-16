#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H

#define ROTATION_MATRIX_DIMENSIONS 3

class RotationMatrix: public Matrix
{
public:
    RotationMatrix(char p_Axis, double p_Angle);
};

#endif // ROTATIONMATRIX_H
