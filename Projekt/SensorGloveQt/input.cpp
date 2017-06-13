#include "includes.h"

Input::Input(QWidget *parent):QObject(parent),
    m_ConnectionType(USBConnection),
    m_RowTransferStarted(),
    m_SingleDataRow(),
    m_PortName(),
    m_PortNumber(),
    m_Manufacturer(),
    m_iterator()
{
    m_DataValues.m_JointAngles = QVector<float>(FINGER_COUNT*3,0);
    m_DataValues.m_FlexSensorValues = QVector<float>(FINGER_COUNT*2,0);
    m_DataValues.m_TensionSensorValues = QVector<int>(FINGER_COUNT,0);
    m_DataValues.m_AccelerometerValues = QVector<float>(ROTATION_ANGLE_COUNT,0);
    m_DataValues.m_RPYangles = QVector<float>(ROTATION_ANGLE_COUNT,0);
    SerialPort = new QSerialPort(this);
    connect(SerialPort, &QSerialPort::readyRead, this, &Input::ReadData);
    FindCOMport();
    ConfigureSPort();
}

QString Input::getPortName()
{
    return m_PortName;
}

Input::DataValues_t Input::getData()
{
    return m_DataValues;
}

void Input::ChangeConnectionType(Input::ConnectionType_t p_ConnecitonType)
{
    m_ConnectionType=p_ConnecitonType;
    FindCOMport();
    ConfigureSPort();
    emit connectionTypeChanged();
}

void Input::FindCOMport()
{
    QString DesiredManufacturer;
    bool COMportFound = false;
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
            COMportFound = true;
            break;
        }
    }
    if(!COMportFound)
    {
        m_Manufacturer = QString();
        m_PortName = QString();
        m_PortNumber = QString();
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
    SerialPort->setStopBits(QSerialPort::OneStop);
    SerialPort->setFlowControl(QSerialPort::NoFlowControl);
}

bool Input::OpenSerialPort()
{
    return SerialPort->open(QIODevice::ReadOnly);
}

void Input::CloseSerialPort()
{
    if(SerialPort->isOpen())
        SerialPort->close();
}

void Input::ReadData()
{
    QByteArray ReceivedData = SerialPort->read(1);
    float JointAngle;
    float FlexValue;
    int TensionValue;
    float AccValue;
    float RotationAngle;

    if(m_RowTransferStarted)
        if(ReceivedData.at(0)=='R')
        {
            QTextStream DataStream(m_SingleDataRow);
            for(int i=0; i<(FINGER_COUNT*3) && !DataStream.atEnd();++i)
            {
                DataStream >> JointAngle;
                m_DataValues.m_JointAngles[i]=JointAngle;
            }
            for(int i=0; i<FINGER_COUNT && !DataStream.atEnd();++i)
            {
                DataStream >> TensionValue;
                m_DataValues.m_TensionSensorValues[i]=TensionValue;
            }
            for(int i=0; i<ROTATION_ANGLE_COUNT && !DataStream.atEnd();++i)
            {
                DataStream >> RotationAngle;
                m_DataValues.m_RPYangles[i]=RotationAngle;
            }
            for(int i=0; i<ROTATION_ANGLE_COUNT && !DataStream.atEnd();++i)
            {
                DataStream >> AccValue;
                m_DataValues.m_AccelerometerValues[i]=AccValue;
            }
            for(int i=0; i<(FINGER_COUNT*2) && !DataStream.atEnd();++i)
            {
                DataStream >> FlexValue;
                m_DataValues.m_FlexSensorValues[i]=FlexValue;
            }
            m_SingleDataRow.clear();
            m_RowTransferStarted=false;

            SerialPort->clear();
            emit dataRecieved();
        }
        else
            m_SingleDataRow.append(ReceivedData);
    else
        if(ReceivedData.at(0)=='S')
            m_RowTransferStarted=true;
}
