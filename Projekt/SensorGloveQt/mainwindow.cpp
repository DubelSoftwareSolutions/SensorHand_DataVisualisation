#include "includes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StartStopButton->setStyleSheet("background-color: rgb(225,240,80)");
    this->setWindowTitle("Sensor Glove Visualization");
    this->setMinimumHeight(ui->ConfigurationWidget->height() + ui->MeasurementWidget->height()
                           +ui->GyroTable->height() + MARGIN*3);
    this->setMinimumWidth(ui->GyroTable->width()+ui->FingersTab->width()+MARGIN*3);

    m_statusLabel = new QLabel;
    ui->statusBar->addWidget(m_statusLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getScene(Scene *p_scene)
{
    scene3D = p_scene;
    AddWidgetToGlove3DLayout(scene3D->widget);
}

void MainWindow::AddWidgetToGlove3DLayout(QWidget *widget)
 {
     widget->resize(600,400);
     ui->centralWidget->width();
     ui->Glove3DLayout->addWidget(widget);
     Glove3DLayoutWidgetIsSet = true;
 }

void MainWindow::InitInputData(Input * data)
{
    InputData = data;
    connect(InputData, &Input::dataRecieved, this, &MainWindow::updateRecievedValues );
    connect(InputData->SerialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::SerialPortErrorHandler);
    m_statusLabel->setText("Serial Closed");
}
// ********************************************************************
// ***************************   private    ***************************   private

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    int width = ui->centralWidget->width() - ui->MeasurementLayout->geometry().width();
    int height = ui->centralWidget->height() - ui->GyroTable->height();
    ui->GyroTable->item(0,0)->setText(QString::number(width));
    if (Glove3DLayoutWidgetIsSet)
    {
        scene3D->widget->resize(width, height);
        ui->MeasurementLayout->geometry().setLeft(width);
        ui->GyroTable->move(MARGIN, height);
        ui->FingersTab->move(ui->GyroTable->width() + MARGIN, height);
        ui->ConfigurationWidget->move(width, MARGIN);
        ui->MeasurementWidget->move(width, MARGIN*2 + ui->ConfigurationWidget->height());
    }
}

void MainWindow::on_StartStopButton_clicked()
{
    if(ui->StartStopButton->text() == "Start")
    {
        if(InputData->OpenSerialPort())
        {
            ui->StartStopButton->setText("Stop");
            ui->StartStopButton->setStyleSheet("background-color: rgb(240,125,70)");
            m_statusLabel->setText("Serial Open: "+InputData->getPortName());
            ui->actionConfiguration->setDisabled(true);
        }
        else
        {
            QMessageBox::critical(this,"Serial Port Error", InputData->SerialPort->errorString());
            m_statusLabel->setText("Serial Error");
        }
    }
    else
    {
        InputData->CloseSerialPort();
        ui->StartStopButton->setText("Start");
        ui->StartStopButton->setStyleSheet("background-color: rgb(225,240,80)");
        m_statusLabel->setText("Serial Closed");
        ui->actionConfiguration->setEnabled(true);
    }
}

void MainWindow::on_CameraOrientationSlider_valueChanged(int value)
{
    ui->CameraOrientationLineEdit->setText(QString::number(value));

    int r = 50*ui->GloveZoomSlider->value() / 100 + 10;
    scene3D->cameraEntity->setPosition(QVector3D(-sin(M_PI*value/180)*r, 10, -cos(M_PI*value/180)*r));

    scene3D->camController->setCamera(scene3D->cameraEntity);

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

void MainWindow::on_GloveZoomSlider_valueChanged(int value)
{
    ui->GloveZoomLineEdit->setText(QString::number(value));

    int r = 50*value / 100 + 10;
    int angle = ui->CameraOrientationSlider->value();
    scene3D->cameraEntity->setPosition(QVector3D(-sin(M_PI*angle/180)*r, 10, -cos(M_PI*angle/180)*r));

    scene3D->camController->setCamera(scene3D->cameraEntity);
}

void MainWindow::on_GloveZoomLineEdit_textEdited(const QString &arg1)
{
    bool isDgt = true;
    for (int i = 0; i < arg1.length(); ++i) {

        isDgt = arg1.at(i).isDigit() && isDgt;
    }
    if (!isDgt)
        ui->GloveZoomLineEdit->setText(QString::number(ui->GloveZoomSlider->value()));
}

void MainWindow::on_GloveZoomLineEdit_editingFinished()
{
    QString arg = ui->GloveZoomLineEdit->text();
    ui->GloveZoomSlider->setValue(arg.toInt());
}

void MainWindow::updateRecievedValues()
{
    ui->Angle1ValLabel->setText(QString::number(InputData->getData().m_JointAngles[0]));
    ui->PressureValLabel->setText(QString::number(InputData->getData().m_TensionSensorValues[0]));
    ui->GyroTable->item(0,0)->setText(QString::number(InputData->getData().m_AccelerometerValues[0]));
    //ui->GyroTable->item(0,1)->setText(QString::number(InputData->getData().m_AccelerometerValues[1]));
    //ui->GyroTable->item(0,2)->setText(QString::number(InputData->getData().m_AccelerometerValues[2]));
    //TODO
}

void MainWindow::SerialPortErrorHandler(QSerialPort::SerialPortError error)
{
    if(error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, "Serial Port Critical Error", InputData->SerialPort->errorString() );
        InputData->SerialPort->close();
        ui->StartStopButton->setText("Start");
        ui->StartStopButton->setStyleSheet("background-color: rgb(225,240,80)");
        m_statusLabel->setText("Serial Closed");
        ui->actionConfiguration->setEnabled(true);
    }
}

