#include "includes.h"

#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QTime>
#include <QtCore/QDebug>

/*Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    */
Chart::Chart(QChart *p_chart):
    m_series(0),
    m_axis(new QValueAxis),
    m_step(0),
    m_x(0),
    m_y(1),
    m_axisXminRange(0),
    m_axisXmaxRange(10),
    m_scrollSum(0)

{
    qsrand((uint) QTime::currentTime().msec());

    QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    m_timer.setInterval(1000);
    m_chart = p_chart;
    m_series = new QSplineSeries(this);
    QPen green(Qt::red);
    green.setWidth(3);
    m_series->setPen(green);
    m_series->append(m_x, m_y);

    m_chart->addSeries(m_series);
    m_chart->createDefaultAxes();
    m_chart->setAxisX(m_axis, m_series);
    m_axis->setTickCount(1);

    m_chart->axisX()->setRange(m_axisXminRange, m_axisXmaxRange);
    m_chart->axisY()->setRange(0, 20);

    m_timer.start();
}

Chart::~Chart()
{

}
void Chart::addValue(float p_value)
{
    qreal x = (m_chart->plotArea().width() / m_axis->tickCount())/2;
    //qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
    m_x += 1;
    m_y = p_value;
    m_series->append(m_x, m_y);

    if (m_series->count() > (m_axis->max() - m_axis->min()))
    {
        m_scrollSum += x;
        m_chart->scroll(x, 0);
    }
}

void Chart::setRangeX(float p_min, float p_max)
{
    m_chart->axisX()->setRange(p_min, p_max);

    m_axisXminRange = p_min;
    m_axisXmaxRange = p_max;
}

void Chart::setRangeY(float p_min, float p_max)
{
    m_chart->axisY()->setRange(p_min, p_max);
}

QVector<float> Chart::getRangeX()
{
    QVector<float> range;
    range.push_back(m_axisXminRange);
    range.push_back(m_axisXmaxRange);
    return range;
}
void Chart::clearChart()
{
    m_chart->scroll(-m_scrollSum,0);
    m_scrollSum = 0;
    m_series->clear();
    m_series->append(0,0);
    m_x = 0;
}

float Chart::getMaxX()
{
    return m_x;
}


void Chart::handleTimeout()
{
    addValue(rand()%20);
    //addValue((/100);

    /*
    if (m_x == 100)
        m_timer.stop();
        */
}

