#include "includes.h"
#include "chartwindow.h"
#include "ui_chartwindow.h"

chartWindow::chartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chartWindow)
{
    ui->setupUi(this);
    AddChartToChartLayout(new QChart());
    connect(InputData, &Input::dataRecieved, this, &chartWindow::updateRecievedValues);
}

chartWindow::~chartWindow()
{
    delete ui;
}

void chartWindow::InitInputData(Input *data)
{
    InputData = data;
}

void chartWindow::AddChartToChartLayout(QChart *p_chart)
{
    p_chart->setTitle("Dynamic chart of pressure");
    p_chart->legend()->hide();
    p_chart->setAnimationOptions(QChart::AllAnimations);
    m_chartView = new QChartView(p_chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    ui->chartLayout->addWidget(m_chartView);
    m_chart = new Chart(m_chartView->chart());
}


void chartWindow::updateRecievedValues()
{
    m_chart->addValue(InputData->getData().m_TensionSensorValues[ui->chartFingerSelect->currentIndex()]);
}
