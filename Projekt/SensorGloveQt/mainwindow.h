#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "input.h"
namespace Ui {
class MainWindow;
}

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

void on_GloveSizeSlider_valueChanged(int value);
void on_GloveSizeLineEdit_textEdited(const QString &arg1);
void on_GloveSizeLineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    //Input *InputData;
};

#endif // MAINWINDOW_H
