#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StartStopButton->setStyleSheet("background-color: rgb(225,240,80)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddWidgetToGlove3DLayout(QWidget *widget)
 {
     widget->resize(600,400);
     ui->centralWidget->width();
     ui->Glove3DLayout->addWidget(widget);
 }

void MainWindow::on_StartStopButton_clicked()
{
    if(ui->StartStopButton->text() == "Start")
    {
        ui->StartStopButton->setText("Stop");
        ui->StartStopButton->setStyleSheet("background-color: rgb(240,125,70)");

    }
    else
    {
        ui->StartStopButton->setText("Start");
        ui->StartStopButton->setStyleSheet("background-color: rgb(225,240,80)");
    }
}

void MainWindow::on_CameraOrientationSlider_valueChanged(int value)
{
    ui->CameraOrientationLineEdit->setText(QString::number(value));
}

void MainWindow::on_CameraOrientationLineEdit_textEdited(const QString &arg1)
{
    bool isDgt = true;
    for (int i = 0; i < arg1.length(); ++i) {

        isDgt = arg1.at(i).isDigit() && isDgt;
    }
    if (!isDgt)
        ui->CameraOrientationLineEdit->setText(QString::number(ui->CameraOrientationSlider->value()));
}

void MainWindow::on_CameraOrientationLineEdit_editingFinished()
{
    QString arg = ui->CameraOrientationLineEdit->text();
    ui->CameraOrientationSlider->setValue(arg.toInt());
}

void MainWindow::on_GloveSizeSlider_valueChanged(int value)
{
    ui->GloveSizeLineEdit->setText(QString::number(value));
}

void MainWindow::on_GloveSizeLineEdit_textEdited(const QString &arg1)
{
    bool isDgt = true;
    for (int i = 0; i < arg1.length(); ++i) {

        isDgt = arg1.at(i).isDigit() && isDgt;
    }
    if (!isDgt)
        ui->GloveSizeLineEdit->setText(QString::number(ui->GloveSizeSlider->value()));
}

void MainWindow::on_GloveSizeLineEdit_editingFinished()
{
    QString arg = ui->GloveSizeLineEdit->text();
    ui->GloveSizeSlider->setValue(arg.toInt());
}
