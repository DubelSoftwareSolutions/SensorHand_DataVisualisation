#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
protected:
    std::vector<EuclideanVector> m_elements;
public:
    Matrix(vector<EuclideanVector> p_vectors=vector<EuclideanVector>());

    EuclideanVector operator [] (int p_index) const;
    EuclideanVector& operator [] (int p_index);

    Matrix operator + (Matrix const & p_matrix) const;
    Matrix operator - (Matrix const & p_matrix) const;
    Matrix operator - () const;
    Matrix operator * (Matrix const & p_matrix) const;
    Matrix operator = (Matrix const & p_matrix);

    EuclideanVector operator * (EuclideanVector const & p_EVector);

    void display();
};

#endif // MATRIX_H
