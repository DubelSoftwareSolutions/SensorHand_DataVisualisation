#include "includes.h"

EuclideanVector::EuclideanVector(double p_v1, double p_v2, double p_v3):m_elements(EVECTOR_DIMENSION_COUNT)
{
    m_elements[0]=p_v1;
    m_elements[1]=p_v2;
    m_elements[2]=p_v3;
}

double EuclideanVector::get_v1() const
{
    return m_elements[0];
}
double &EuclideanVector::set_v1()
{
    return m_elements[0];
}

double EuclideanVector::get_v2() const
{
    return m_elements[1];
}
double &EuclideanVector::set_v2()
{
    return m_elements[1];
}

double EuclideanVector::get_v3() const
{
    return m_elements[2];
}
double &EuclideanVector::set_v3()
{
    return m_elements[2];
}

EuclideanVector EuclideanVector::operator +(const EuclideanVector & p_evector) const
{
    EuclideanVector OutputEVector;
    for(int i=0;i<EVECTOR_DIMENSION_COUNT;++i)
        OutputEVector[i] = this->m_elements[i]+p_evector.m_elements[i];
    return OutputEVector;
}

EuclideanVector EuclideanVector::operator -(const EuclideanVector &p_evector) const
{
    EuclideanVector OutputEVector;
    for(int i=0;i<EVECTOR_DIMENSION_COUNT;++i)
        OutputEVector[i] = this->m_elements[i]-p_evector.m_elements[i];
    return OutputEVector;
}

EuclideanVector EuclideanVector::operator -() const
{
    EuclideanVector OutputEVector;
    for(int i=0;i<EVECTOR_DIMENSION_COUNT;++i)
        OutputEVector[i] = -this->m_elements[i];
    return OutputEVector;
}

EuclideanVector EuclideanVector::operator =(const EuclideanVector &p_evector)
{
    for(int i=0;i<EVECTOR_DIMENSION_COUNT;++i)
        this->m_elements[i]=p_evector.m_elements[i];
    return *this;
}

EuclideanVector EuclideanVector::operator *(const EuclideanVector &p_evector) const
{
    EuclideanVector OutputEVector;
    OutputEVector[0]=this->m_elements[1]*p_evector.m_elements[2]
            -this->m_elements[2]*p_evector.m_elements[1];
    OutputEVector[1]=this->m_elements[2]*p_evector.m_elements[0]
            -this->m_elements[0]*p_evector.m_elements[2];
    OutputEVector[2]=this->m_elements[0]*p_evector.m_elements[1]
            -this->m_elements[1]*p_evector.m_elements[0];
    return OutputEVector;
}

double EuclideanVector::operator [](int p_index) const
{
    return this->m_elements[p_index];
}

double &EuclideanVector::operator [](int p_index)
{
    return this->m_elements[p_index];
}

double EuclideanVector::Norm() const
{
    double OutputValue;
    for(auto currentElement: this->m_elements)
        OutputValue+=pow(currentElement,2);
    return sqrt(OutputValue);
}

void EuclideanVector::display() const
{
    std::cout<<'(';
    for(auto currentElement: this->m_elements)
        std::cout<<currentElement<<',';
    std::cout<<')';
}


double dotProduct(const EuclideanVector &p_evector1, const EuclideanVector &p_evector2)
{
    double OutputValue;
    for(int i=0;i<EVECTOR_DIMENSION_COUNT;++i)
        OutputValue += p_evector1[i] * p_evector2[i];
    return OutputValue;
}

EuclideanVector operator *(const EuclideanVector &p_evector, double p_ConstantValue)
{
    EuclideanVector OutputEVector;
    for(int i=0;i<EVECTOR_DIMENSION_COUNT;++i)
        OutputEVector[i]=p_ConstantValue*p_evector[i];
    return OutputEVector;
}

EuclideanVector operator *(double p_ConstantValue, const EuclideanVector &p_evector)
{
    EuclideanVector OutputEVector;
    for(int i=0;i<EVECTOR_DIMENSION_COUNT;++i)
        OutputEVector[i]=p_ConstantValue*p_evector[i];
    return OutputEVector;
}
