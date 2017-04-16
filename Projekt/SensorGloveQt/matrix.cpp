#include "includes.h"

Matrix::Matrix(vector<EuclideanVector> p_vectors):m_elements(p_vectors)
{}

EuclideanVector Matrix::operator [](int p_index) const
{
    return m_elements[p_index];
}

EuclideanVector &Matrix::operator [](int p_index)
{
    return m_elements[p_index];
}

Matrix Matrix::operator +(const Matrix &p_matrix) const
{
    Matrix OutputMatrix(p_matrix.m_elements);
    for(int i=0; i<this->m_elements.size(); ++i)
        OutputMatrix.m_elements[i] = this->m_elements[i] + p_matrix.m_elements[i];
    return OutputMatrix;
}

Matrix Matrix::operator -(const Matrix &p_matrix) const
{
    Matrix OutputMatrix(p_matrix.m_elements);
    for(int i=0; i<this->m_elements.size(); ++i)
        OutputMatrix.m_elements[i] = this->m_elements[i] - p_matrix.m_elements[i];
    return OutputMatrix;
}

Matrix Matrix::operator -() const
{
    Matrix OutputMatrix(this->m_elements);
    for(int i=0; i<this->m_elements.size(); ++i)
        OutputMatrix.m_elements[i] = -this->m_elements[i];
    return OutputMatrix;
}

Matrix Matrix::operator *(const Matrix &p_matrix) const
{
    Matrix OutputMatrix(this->m_elements);
    for(int i=0; i<this->m_elements.size(); ++i)
        OutputMatrix.m_elements[i] = *this * p_matrix.m_elements[i];
    return OutputMatrix;
}

Matrix Matrix::operator =(const Matrix &p_matrix)
{
    for(int i=0; i<this->m_elements.size(); ++i)
        this->m_elements[i]=p_matrix.m_elements[i];
    return *this;
}

EuclideanVector Matrix::operator *(const EuclideanVector &p_EVector)
{
    EuclideanVector OutputEVector;
    for(int i=0; i<this->m_elements.size(); ++i)
        OutputEVector = this->m_elements[i] * p_EVector;
    return OutputEVector;
}

void Matrix::display()
{
    for(auto CurrentEVector: this->m_elements)
    {
        CurrentEVector.display();
        cout<<endl;
    }
}
