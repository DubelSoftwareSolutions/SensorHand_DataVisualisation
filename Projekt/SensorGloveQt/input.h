#ifndef INPUT_H
#define INPUT_H

/*!
 * \file
 * \brief Definicja klasy Input
 *
 * Plik zwiera definicję klasy Input, jest klasą pochodną
 * klas QBluetoothTransferManager oraz QSerialPort
 */

#include <QtBluetooth>
#include <QtSerialPort>

/*
namespace Id {
class Input;
}
*/

/*!
 * \brief Klasa jest narzędziem do pobierania danych
 * Inicjalizuje kąty między stawami, wskazania czujników tensometrycznych,
 * wskazania akcelerometru i typ połączenia z rękawicą sensoryczną
 *
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
