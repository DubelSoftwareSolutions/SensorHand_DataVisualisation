#ifndef EUCLIDEANVECTOR_H
#define EUCLIDEANVECTOR_H

#define EVECTOR_DIMENSION_COUNT 3

class EuclideanVector
{
protected:
    QVector<double> m_elements;
public:
    EuclideanVector(double p_v1=0, double p_v2=0, double p_v3=0);
    double get_v1() const;
    double& set_v1();
    double get_v2() const;
    double& set_v2();
    double get_v3() const;
    double& set_v3();

    EuclideanVector operator + (EuclideanVector const& p_evector) const;
    EuclideanVector operator - (EuclideanVector const& p_evector) const;
    EuclideanVector operator - () const;
    EuclideanVector operator = (EuclideanVector const& p_evector);
    EuclideanVector operator * (EuclideanVector const& p_evector) const;

    double operator [] (int p_index) const;
    double& operator [] (int p_index);

    double Norm() const;
    void display() const;
};

double dotProduct (EuclideanVector const& p_evector1, EuclideanVector const& p_evector2);
EuclideanVector operator * (EuclideanVector const& p_evector, double p_ConstantValue);
EuclideanVector operator * (double p_ConstantValue, EuclideanVector const& p_evector);

#endif // EVECTOR_H
