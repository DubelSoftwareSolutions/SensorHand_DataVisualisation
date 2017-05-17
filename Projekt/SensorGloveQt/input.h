#ifndef INPUT_H
#define INPUT_H
#include <QtBluetooth>
#include <QtSerialPort>
/*
namespace Id {
class Input;
}
*/

class Input: QBluetoothTransferManager, QSerialPort
{
    enum ConnectionType_t {BluetoothConnection, USBConnection};

    QVector<float> m_JointAngles;
    QVector<int> m_TensionSensorValues;
    QVector<float> m_AccelerometerValues;
    ConnectionType_t m_ConnectionType;
public:
    Input();

    void ChangeConnectionType(ConnectionType_t p_ConnecitonType);
    void ConfigureInput();
};

#endif // INPUT_H
