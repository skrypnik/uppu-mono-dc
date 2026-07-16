#pragma once

#include <QObject>

#include "Packet.h"

class QTcpSocket;
class QTimer;

namespace Enercom::Network
{
    /**
     * Network params private implementation
     */
    class NetworkSettings;

    /**
     * Network searcher
     */
    class Searcher;

    /**
     * Network module class
     */
    class Module final : public QObject
    {
        Q_OBJECT

    public:
        /**
        * Constructs network object
        * @param parent parent QObject to call safe deleter
        */
        explicit Module(QObject* parent = nullptr);

        /**
        * Destroys network object
        */
        ~Module() override;

        /**
         * Initializes necessary data
         */
        void initialize();

    public:
        /**
        * Connects to remote host
        */
        Q_INVOKABLE void connectToHost() const;

        /**
        * Disconnects from remote host
        */
        Q_INVOKABLE void disconnectFromHost() const;

        /**
         * Sets connection params
         * @param host connection host
         * @param port connection port
         */
        Q_INVOKABLE void setConnectionParams(const QString& host, const QString& port) const;

    public:
        /**
         * Sends device info request
         */
        Q_INVOKABLE void sendDeviceInfoRequest();

        /**
         * Sends set meters info request
         * @param count meters count
         * @param speed baud rate
         * @param type input type
         * @param voltage input voltage
         */
        Q_INVOKABLE void sendSetMetersInfoRequest(int count, int speed, int type, float voltage);

        /**
         * Sends get meters info request
         */
        Q_INVOKABLE void sendGetMetersInfoRequest();

        /**
        * Sends set meter params request
        * @param index meter index
        * @param address meter MODBUS address
        * @param current meter current
        * @param voltage meter voltage
        * @param constant meter constant coefficient
        * @param factor meter impulse factor
        */
        Q_INVOKABLE void sendSetGivenMeterRequest(int index, int address, float current, float voltage, int constant, int factor);

        /**
         * Get meter params request
         * @param index meter index
         */
        Q_INVOKABLE void sendGetGivenMeterRequest(int index);

        /**
         * Sends allow meter voltage to flow request
         * @param allow allow flag (0 - off, 1 -on)
         */
        Q_INVOKABLE void sendAllowVoltageFlowRequest(int allow);

        /**
         * Sends get meter readings request
         * @param index meter index
         * @return TLV formated request
         */
        Q_INVOKABLE void sendGetMeterReadingsRequest(int index);

        /**
         * Sends get calibrator readings request
         * @param reserved reserved param
         * @return TLV formated request
         */
        Q_INVOKABLE void sendGetCalibratorReadingsRequest(int reserved = 0x00);

        /**
         * Sends calibrator info request
         * @param type meter type
         * @param constant meter constant coefficient
         * @param current meter current
         * @param voltage meter voltage
         * @return TLV formated request
         */
        Q_INVOKABLE void sendSetCalibratorInfoRequest(int type, int constant, float current, float voltage);

        /**
         * Sends get calibrator info request
         * @param reserved reserved param
         * @return TLV formated request
         */
        Q_INVOKABLE void sendGetCalibratorInfoRequest(int reserved = 0x00);

        /**
         * Sends set high voltage info request
         * @param mode operating mode
         * @param volREG regulator voltage
         * @param volDAC DAC voltage
         * @return TLV formated request
         */
        Q_INVOKABLE void sendSetHiVoltageInfoRequest(int mode, float volREG, float volDAC);

        /**
         * Sends get high voltage info request
         * @param reserved reserved param
         * @return TLV formated request
         */
        Q_INVOKABLE void sendGetHiVoltageInfoRequest(int reserved = 0x00);

        /**
         * Sends set low voltage info request
         * @param mode operating mode
         * @param volREG regulator voltage
         * @param volDAC DAC voltage
         * @return TLV formated request
         */
        Q_INVOKABLE void sendSetLoVoltageInfoRequest(int mode, float volREG, float volDAC);

        /**
         * Sends get low voltage info request
         * @param reserved reserved param
         * @return TLV formated request
         */
        Q_INVOKABLE void sendGetLoVoltageInfoRequest(int reserved = 0x00);

        /**
         * Sends get status request
         * @param reserved reserved param
         * @return TLV formated request
         */
        Q_INVOKABLE void sendGetStatusRequest(int reserved = 0x00);

        /**
         * Sends allow voltage generation request
         * @param hiVoltage hi voltage
         * @param loVoltage lo voltage
         * @return TLV formated request
         */
        Q_INVOKABLE void sendAllowVoltageGenerationRequest(int hiVoltage, int loVoltage);

        /**
         * Sends set network info request
         * @param host network address
         * @param mask network mask
         * @param port network port
         * @return TLV formated request
         */
        Q_INVOKABLE void sendSetNetworkInfoRequest(const QString& host, const QString& mask, int port);

    private:
        /**
        * Starts device connection
        * @param host device address or hostname
        * @param port device network port
        */
        void start(const QString& host, uint16_t port) const;

        /**
        * Sends raw data to remote host
        * @param data data to send
        */
        void send(const QByteArray& data);

        /**
        * Stops server connection
        */
        void stop() const;

        /**
        * Handles incoming data
        */
        void handleIncomingData();

    signals:
        /**
         * Emits, when device connection established
         */
        void deviceConnected();

        /**
         * Emits, when device connection failed
         */
        void deviceDisconnected();

        /**
         * Emits, when module sends request to device
         * @param packet request packet data
         */
        void outgoingPacket(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
         * Emits, when module receives response from device
         * @param packet response packet data
         */
        void incomingPacket(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
         * Emits, when module receives response on broadcast request
         * @param packet response packet data
         */
        void incomingBroadcastPacket(const Enercom::Network::Packet::Fields::Ptr& packet);

    public slots:
        /**
         * Device info received handler
         * @param data packet data
         */
        void onDeviceInfoReceived(const Enercom::Network::Packet::Fields::Ptr& data);

    private slots:
        /**
        * TCP client socket connect handler
        */
        void onConnected();

        /**
        * TCP client socket disconnect handler
        */
        void onDisconnected();

        /**
        * Server reply handler
        */
        void onReplyReceived();

        /**
         * Sends device info request (periodic)
         */
        void onSendDeviceInfoRequest();

    private:
        /**
        * Device network settings
        */
        NetworkSettings* params_;

        /**
        * TCP client socket to connect the device group
        */
        QTcpSocket* socket_;

        /**
         * Device data request timer
         */
        QTimer* requester_;

        /**
        * Network searcher
        */
        Searcher* searcher_;

        /**
         * Incoming data buffer
         */
        QByteArray data_;
    };

}
