#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
 * \file
 * \brief Definicja klasy MainWindow
 *
 * Plik zawiera definicję klasy MainWindow, która
 * jest klasą pochodną klasy QMainWindow
 */

#include <QMainWindow>
#include "input.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief Modeluje strukturę GUI programu
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
//void InitInputData(Input & data);

private slots:
void on_StartStopButton_clicked();

void on_CameraOrientationSlider_valueChanged(int value);
void on_CameraOrientationLineEdit_textEdited(const QString &arg1);
void on_CameraOrientationLineEdit_editingFinished();

void on_GloveZoomSlider_valueChanged(int value);
void on_GloveZoomLineEdit_textEdited(const QString &arg1);
void on_GloveZoomLineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    Input *InputData;
};

#endif // MAINWINDOW_H
