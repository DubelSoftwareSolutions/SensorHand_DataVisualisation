#ifndef INPUT_H
#define INPUT_H

/*!
 * \file
 * \brief Definicja klasy Input
 *
 * Plik zwiera definicję klasy Input, jest klasą pochodną
 * klas QBluetoothTransferManager oraz QSerialPort
 *
 */

#include <QtBluetooth>
#include <QtSerialPort>
#include "errorhandler.h"

#define BLUETOOTH_MANUFACTURER "Prolific"
#define UART_MANUFACTURER "Prolific"
#define USB_MANUFACTURER "STMicroelectronics."

#define BLUETOOTH_BAUDRATE QSerialPort::Baud9600
#define UART_BAUDRATE QSerialPort::Baud115200
#define USB_BAUDRATE QSerialPort::Baud115200

#define ROTATION_ANGLE_COUNT 3

/*
namespace Id {
class Input;
}
*/

/*!
 * \brief Klasa jest narzędziem do pobierania danych
 *
 * Inicjalizuje kąty między stawami, wskazania czujników tensometrycznych,
 * wskazania akcelerometru i typ połączenia z rękawicą sensoryczną
 *
 */
class Input: public QObject
{
    Q_OBJECT
public:
    enum ConnectionType_t {BluetoothConnection, UARTConnection, USBConnection};
private:

    /*!
     * \brief Struktura służąca do przechowywania danych wejściowych
     */
    struct DataValues_t
    {
        QVector<float> m_JointAngles;
        QVector<float> m_FlexSensorValues;
        QVector<int> m_TensionSensorValues;
        QVector<float> m_AccelerometerValues;
        QVector<float> m_RPYangles;
    };

    QString m_PortName;
    QString m_PortNumber;
    QString m_Manufacturer;
    int m_iterator;

    bool m_RowTransferStarted;
    QByteArray m_SingleDataRow;

    DataValues_t m_DataValues;
    ConnectionType_t m_ConnectionType;
public:
    QSerialPort *SerialPort;

    explicit Input(QWidget *parent = nullptr);
    QString getPortName();
    DataValues_t getData();
    void ChangeConnectionType(ConnectionType_t p_ConnecitonType);
    bool OpenSerialPort();
    void CloseSerialPort();
private:
    void FindCOMport();
    void ConfigureSPort();
public slots:
    void ReadData();
signals:
    void dataRecieved();
    void dataRecievedChart();
    void connectionTypeChanged();
};

#endif // INPUT_H
