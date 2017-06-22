#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

/*!
 * \file
 * \brief Definicja klasy chartWindow
 *
 * Plik zwiera definicję klasy chartWindow, która
 * jest klasą pochodną klasy QMainWindow
 */

#include <QDialog>
#include <QtCharts/QChartView>
#include "input.h"
#include "chart.h"
namespace Ui {
class chartWindow;
}

/*!
 * \brief Pośredniczy w wyświetlaniu wykresów dynamicznych
 *
 * Inicjalizuje okno z widgetem wykresu dynamicznego oraz
 * widgetami wykorzystywanymi do konfiguracji danych wejściowych
 * i zakresu wyświetlanego wykresu. Klasa pobiera dane z obiektu
 * typu Input co ustalony kwant czasu, a następnie przeprowadza
 * wizualizajcę danych w układzie kartezjańskim.
 *
 */

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
