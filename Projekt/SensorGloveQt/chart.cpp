#include "includes.h"

/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

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
    m_x(5),
    m_y(1),
    m_axisXminRange(0),
    m_axisXmaxRange(500)

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
    m_axis->setTickCount(5);

    m_chart->axisX()->setRange(m_axisXminRange, m_axisXmaxRange);
    m_chart->axisY()->setRange(0, 500);

    //m_timer.start();
}

Chart::~Chart()
{

}
void Chart::addValue(float p_value)
{
    qreal x = m_chart->plotArea().width() / m_axis->tickCount();
    qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
    m_x += y;
    m_y = p_value;
    m_series->append(m_x, m_y);
    m_chart->scroll(x, 0);
    if (m_series->count() > m_axis->tickCount());
}

void Chart::setRangeX(float p_min, float p_max)
{
    m_axisXminRange = p_min;
    m_axisXmaxRange = p_max;
    m_chart->axisX()->setRange(p_min, p_max);
}

void Chart::setRangeY(float p_min, float p_max)
{
    m_chart->axisY()->setRange(p_min, p_max);
}


void Chart::handleTimeout()
{
    addValue(8);
    /*
    if (m_x == 100)
        m_timer.stop();
        */
}
