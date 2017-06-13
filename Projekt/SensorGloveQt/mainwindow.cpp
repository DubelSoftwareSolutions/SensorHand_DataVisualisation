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
            ui->CommunicationBox->setDisabled(true);
            ui->CameraOrientationSlider->setDisabled(true);
            ui->CameraOrientationSlider_2->setDisabled(true);
            ui->CameraOrientationSlider_3->setDisabled(true);
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
        ui->CommunicationBox->setEnabled(true);
        ui->CameraOrientationSlider->setEnabled(true);
        ui->CameraOrientationSlider_2->setEnabled(true);
        ui->CameraOrientationSlider_3->setEnabled(true);
    }
}

void MainWindow::on_CameraOrientationSlider_valueChanged(int value)
{
    float fvalue = M_PI * (float)value / 180;
    float fvalue2 = M_PI * (float)ui->CameraOrientationSlider_2->value()/ 180;
    float fvalue3 = M_PI * (float)ui->CameraOrientationSlider_3->value()/ 180;
    scene3D->SetHandRotation(fvalue, fvalue2, fvalue3);
}

void MainWindow::on_CameraOrientationSlider_2_valueChanged(int value)
{
    float fvalue = M_PI * (float)ui->CameraOrientationSlider->value()/ 180;
    float fvalue2 = M_PI * (float)value / 180;
    float fvalue3 = M_PI * (float)ui->CameraOrientationSlider_3->value()/ 180;
    scene3D->SetHandRotation(fvalue, fvalue2, fvalue3);
}

void MainWindow::on_CameraOrientationSlider_3_valueChanged(int value)
{
    float fvalue = M_PI * (float)ui->CameraOrientationSlider->value()/ 180;
    float fvalue2 = M_PI * (float)ui->CameraOrientationSlider_2->value()/ 180;
    float fvalue3 = M_PI * (float)value / 180;
    scene3D->SetHandRotation(fvalue, fvalue2, fvalue3);
}

void MainWindow::on_GloveZoomSlider_valueChanged(int value)
{
    ui->GloveZoomLineEdit->setText(QString::number(value));

    scene3D->setCameraDistance((float)value);
    scene3D->SetHandRotation(InputData->getData().m_AccelerometerValues[0],
                             InputData->getData().m_AccelerometerValues[1],
                             InputData->getData().m_AccelerometerValues[2]);
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

void MainWindow::on_CommunicationBox_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0: //USB
        InputData->ChangeConnectionType(Input::ConnectionType_t::USBConnection);
        break;
    case 1: //UART
        InputData->ChangeConnectionType(Input::ConnectionType_t::UARTConnection);
        break;
    case 2: //BLT
        InputData->ChangeConnectionType(Input::ConnectionType_t::BluetoothConnection);
        break;
    }
}

void MainWindow::updateRecievedValues()
{
    QVector<float> ThumbAngles(INDEX_JOINT_COUNT,0);
    for(int i=0; i<INDEX_JOINT_COUNT;++i)
        ThumbAngles[i] = InputData->getData().m_JointAngles[i];
    QVector<float> IndexAngles(INDEX_JOINT_COUNT,0);
    for(int i=0; i<INDEX_JOINT_COUNT;++i)
        IndexAngles[i] = InputData->getData().m_JointAngles[i+INDEX_JOINT_COUNT*1];
    QVector<float> MiddleAngles(INDEX_JOINT_COUNT,0);
    for(int i=0; i<INDEX_JOINT_COUNT;++i)
        MiddleAngles[i] = InputData->getData().m_JointAngles[i+INDEX_JOINT_COUNT*2];
    QVector<float> RingAngles(INDEX_JOINT_COUNT,0);
    for(int i=0; i<INDEX_JOINT_COUNT;++i)
        RingAngles[i] = InputData->getData().m_JointAngles[i+INDEX_JOINT_COUNT*3];
    QVector<float> PinkyAngles(INDEX_JOINT_COUNT,0);
    for(int i=0; i<INDEX_JOINT_COUNT;++i)
        PinkyAngles[i] = InputData->getData().m_JointAngles[i+INDEX_JOINT_COUNT*4];
    QVector<QVector<float>> HandJointAngles;
    HandJointAngles.push_back(ThumbAngles);
    HandJointAngles.push_back(IndexAngles);
    HandJointAngles.push_back(MiddleAngles);
    HandJointAngles.push_back(RingAngles);
    HandJointAngles.push_back(PinkyAngles);

    scene3D->SetHandTransformation(HandJointAngles);
    scene3D->SetHandFingertipValues(InputData->getData().m_TensionSensorValues);
    scene3D->SetHandRotation(InputData->getData().m_AccelerometerValues[0],
                             InputData->getData().m_AccelerometerValues[1],
                             InputData->getData().m_AccelerometerValues[2]);

    ui->CameraOrientationSlider->setValue((int)InputData->getData().m_AccelerometerValues[0]);
    ui->CameraOrientationSlider_2->setValue((int)InputData->getData().m_AccelerometerValues[1]);
    ui->CameraOrientationSlider_3->setValue((int)InputData->getData().m_AccelerometerValues[2]);

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
        ui->CommunicationBox->setEnabled(true);
    }
}

