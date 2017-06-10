#include "includes.h"

Input::Input(QWidget *parent):QObject(parent),
    m_ConnectionType(USBConnection),
    m_RowTransferStarted(),
    m_SingleDataRow(),
    m_JointAngles(),
    m_TensionSensorValues(),
    m_AccelerometerValues(),
    m_PortName(),
    m_PortNumber(),
    m_Manufacturer()
{
    SerialPort = new QSerialPort(this);
    connect(SerialPort, &QSerialPort::readyRead, this, &Input::ReadData);
    FindCOMport();
    ConfigureSPort();
}

void Input::ChangeConnectionType(Input::ConnectionType_t p_ConnecitonType)
{
    m_ConnectionType=p_ConnecitonType;
    FindCOMport();
    emit connectionTypeChanged();
}

QSerialPort* Input::getSerialPort() const
{
    return SerialPort;
}

void Input::FindCOMport()
{
    QString DesiredManufacturer;
    switch(m_ConnectionType)
    {
    case BluetoothConnection:
        DesiredManufacturer = BLUETOOTH_MANUFACTURER;
        break;
    case UARTConnection:
        DesiredManufacturer = UART_MANUFACTURER;
        break;
    case USBConnection:
        DesiredManufacturer = USB_MANUFACTURER;
    }

    const auto PortInfo = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &information: PortInfo)
    {
        if(!DesiredManufacturer.compare(information.manufacturer()))
        {
            m_Manufacturer = information.manufacturer();
            m_PortNumber = information.serialNumber();
            m_PortName = information.portName();
            break;
        }
    }
}

void Input::ConfigureSPort()
{
    switch(m_ConnectionType)
    {
    case BluetoothConnection:
        SerialPort->setBaudRate(BLUETOOTH_BAUDRATE);
        break;
    case UARTConnection:
        SerialPort->setBaudRate(UART_BAUDRATE);
        break;
    case USBConnection:
        SerialPort->setBaudRate(USB_BAUDRATE);
    }
    SerialPort->setPortName(m_PortName);
    SerialPort->setDataBits(QSerialPort::Data8);
    SerialPort->setParity(QSerialPort::NoParity);
    SerialPort->setStopBits(QSerialPort::OneAndHalfStop);
    SerialPort->setFlowControl(QSerialPort::NoFlowControl);
}

void Input::OpenCloseSPort()
{
    if(SerialPort->isOpen())
        SerialPort->close();
    else
        SerialPort->open(QIODevice::ReadOnly);
}

void Input::ReadData()
{
    QByteArray ReceivedData = SerialPort->read(1);
    float JointAngle;
    int TensionValue;
    float RotationAngle;
    if(m_RowTransferStarted)
        if(ReceivedData.at(0)=='R')
        {
            QTextStream DataStream(m_SingleDataRow);
            for(int i=0; i<(FINGER_COUNT*2) && !DataStream.atEnd();++i)
            {
                JointAngle;
                DataStream >> JointAngle;
                m_JointAngles.push_back(JointAngle);
            }
            for(int i=0; i<FINGER_COUNT && !DataStream.atEnd();++i)
            {
                TensionValue;
                DataStream >> TensionValue;
                m_TensionSensorValues.push_back(TensionValue);
            }
            for(int i=0; i<ROTATION_ANGLE_COUNT && !DataStream.atEnd();++i)
            {
                RotationAngle;
                DataStream >> RotationAngle;
                m_AccelerometerValues.push_back(RotationAngle);
            }
            m_SingleDataRow.clear();
            for(float var: m_JointAngles)
                std::cout<<var<<' ';
            std::cout<<std::endl;
            m_RowTransferStarted=false;
            //*******************************                  otutaj robi emit       *********
            emit dataRecieved();
        }
        else
            m_SingleDataRow.append(ReceivedData);
    else
        if(ReceivedData.at(0)=='S')
            m_RowTransferStarted=true;
}
