#ifndef INPUT_H
#define INPUT_H


class Input: QBluetoothTransferManager, QSerialPort
{
    enum ConnectionType_t {BluetoothConnection, USBConnection};

    QVector<double> m_JointAngles;
    QVector<double> m_TensionSensorValues;
    QVector<double> m_AccelerometerValues;
    ConnectionType_t m_ConnectionType;
public:
    Input();

    void ChangeConnectionType(ConnectionType_t p_ConnecitonType);
    void ConfigureInput();
};

#endif // INPUT_H
