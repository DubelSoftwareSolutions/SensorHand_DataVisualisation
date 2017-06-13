#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define MARGIN 10

/*!
 * \file
 * \brief Definicja klasy MainWindow
 *
 * Plik zawiera definicję klasy MainWindow, która
 * jest klasą pochodną klasy QMainWindow
 */

#include <QMainWindow>
#include <QtCharts/qchartview.h>
#include <QLabel>
#include <cmath>
#include "scene.h"
#include "input.h"



namespace Ui {
class MainWindow;
}

/*!
 * \brief Modeluje strukturę GUI programu
 *
 * Inicjalizuje głowne okno programu, jego elementy składowe
 * w postaci wdgetów oraz wczytuje zewnętrzny widget trójwymiarowej wizualizacji
 * dłoni. Klasa pobiera dane z obiektu typu Input, aktualizeje dane w modelu
 * dłoni typy Hand i na ich podstawie wyświetla aktualne informacje dotyczące
 * położenia stawów, nacisku i wskazania akcelerometru.
 * Pozwala na zmianę perspektywy widoku na model trójwymiarowy,
 * uruchomienie i zatrzymanie pomiarów
 *
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void AddWidgetToGlove3DLayout(QWidget *widget);
void getScene(Scene *p_scene);
void InitInputData(Input *data);

private slots:
void resizeEvent(QResizeEvent *event);
void on_StartStopButton_clicked();

void on_CameraOrientationSlider_valueChanged(int value);
void on_CameraOrientationSlider_2_valueChanged(int value);
void on_CameraOrientationSlider_3_valueChanged(int value);

void on_GloveZoomSlider_valueChanged(int value);
void on_GloveZoomLineEdit_textEdited(const QString &arg1);
void on_GloveZoomLineEdit_editingFinished();

void on_CommunicationBox_currentIndexChanged(int index);

void on_RotationResetButton_clicked();
void on_FingersTab_currentChanged(int index);

void on_AccelerometerCheckBox_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Input *InputData;
    Scene *scene3D;
    QLabel *m_statusLabel;
    bool Glove3DLayoutWidgetIsSet = false;
//signals:

public slots:
    void updateRecievedValues();
    void SerialPortErrorHandler(QSerialPort::SerialPortError error);
};

#endif // MAINWINDOW_H
