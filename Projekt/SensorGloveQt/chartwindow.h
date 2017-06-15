#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QDialog>
#include <QtCharts/QChartView>
#include "input.h"
#include "chart.h"
namespace Ui {
class chartWindow;
}

class chartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit chartWindow(QWidget *parent = 0);
    ~chartWindow();
    void InitInputData(Input *data);
    void AddChartToChartLayout(QChart *p_chart);
    void clearChart();
public slots:
    void updateRecievedValues();

    void on_chartScaleLine_editingFinished();
    void on_chartScaleLine_textEdited(const QString &arg1);

private slots:
    void on_chartFingerSelect_currentIndexChanged(int index);

private:
    Ui::chartWindow *ui;
    Input *InputData;
    Chart *m_chart;
    QChartView *m_chartView;
};

#endif // CHARTWINDOW_H
