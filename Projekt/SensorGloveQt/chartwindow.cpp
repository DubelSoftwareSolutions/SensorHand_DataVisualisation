#include "includes.h"
#include "chartwindow.h"
#include "ui_chartwindow.h"

chartWindow::chartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chartWindow)
{
    ui->setupUi(this);
    AddChartToChartLayout(new QChart());
    this->setWindowTitle("Tension sensor chart");
}

chartWindow::~chartWindow()
{
    delete ui;
}

void chartWindow::InitInputData(Input *data)
{
    InputData = data;
    connect(InputData, &Input::dataRecievedChart, this, &chartWindow::updateRecievedValues);
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
    ui->chartScaleLine->setText(QString::number(m_chart->getRangeX()[1]));
}

void chartWindow::clearChart()
{
    m_chart->clearChart();
}


void chartWindow::updateRecievedValues()
{
    if(this->isVisible())
        m_chart->addValue(InputData->getData().m_TensionSensorValues[ui->chartFingerSelect->currentIndex()]);
}


void chartWindow::on_chartScaleLine_textEdited(const QString &arg1)
{
    bool isDgt = true;
    for (int i = 0; i < arg1.length(); ++i) {

        isDgt = arg1.at(i).isDigit() && isDgt;
    }
    if (!isDgt)
        ui->chartScaleLine->setText(QString::number((m_chart->getRangeX())[1]));
}

void chartWindow::on_chartScaleLine_editingFinished()
{
    QString arg = ui->chartScaleLine->text();
    m_chart->setRangeX(0,arg.toInt());
}

