#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

//![1]
class Chart: QObject
{
    Q_OBJECT
public:
    //Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    Chart(QChart *p_chart);
    virtual ~Chart();
    void addValue(float p_value);
    void setRangeX(float p_min, float p_max);
    void setRangeY(float p_min, float p_max);   
    QVector<float> getRangeX();
    void clearChart();
    float getMaxX(void);

public slots:
    void handleTimeout();

private:
    QChart *m_chart;
    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axis;
    float m_step;
    float m_x;
    float m_y;
    float m_axisXminRange;
    float m_axisXmaxRange;
    float m_scrollSum;

};
//![1]


#endif // CHART_H
