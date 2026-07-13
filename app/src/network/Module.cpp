#include "Module.h"

#include <config/Common.h>

#include <QTcpSocket>
#include <QUdpSocket>

#include "Packet.h"

namespace Enercom::Network
{
    constexpr uint16_t broadcastSN = 0x00;

    class NetworkSettings
    {
        friend class Module;

        /**
        * Device address or hostname
        */
        QString address = Enercom::Config::Common::get().root()["network"]["host"].toString();

        /**
        * Device network port. Defaults: 63500
        */
        uint16_t networkPort = Enercom::Config::Common::get().root()["network"]["host"].toInt();

        /**
        * Device service port. Defaults: 57555
        */
        uint16_t servicePort = Enercom::Config::Common::get().root()["service"]["port"].toInt();

        /**
         * Current device serial number
         */
        uint16_t serialNumber = 0x00;
    };

    Module::Module(QObject* parent)
        : QObject(parent)
        , params_(nullptr)
        , socket_(new QTcpSocket(this))
        , searcher_(new QUdpSocket(this))
    {
        QObject::connect(socket_, &QTcpSocket::connected,    this, &Module::onConnected);
        QObject::connect(socket_, &QTcpSocket::disconnected, this, &Module::onDisconnected);
        QObject::connect(socket_, &QTcpSocket::readyRead,    this, &Module::onReplyReceived);

        QObject::connect(searcher_, &QUdpSocket::readyRead, this, &Module::onBroadcastReplyReceived);
    }

    Module::~Module()
    {
        delete params_;
    }

    void Module::initialize()
    {
        params_ = new NetworkSettings();

        searcher_->bind(QHostAddress::Any, params_->servicePort);
    }

    void Module::start(const QString& host, const uint16_t port) const
    {
        qDebug() << Q_FUNC_INFO;

        params_->address = host;
        params_->networkPort = port;

        socket_->connectToHost(host, port);
    }

    void Module::send(const QByteArray& data)
    {
        qDebug() << Q_FUNC_INFO;

        qDebug() << "[SOCKET] >>>" << data.toHex();

        const auto packet = Packet::fromRawData(data);

        if (packet == nullptr) return;

        emit this->outgoingPacket(packet);

        socket_->write(data);
    }

    void Module::stop() const
    {
        qDebug() << Q_FUNC_INFO;

        if (socket_->state() == QAbstractSocket::ConnectedState) socket_->disconnectFromHost();
    }

    void Module::handleIncomingData()
    {
        auto size = data_[0x03] + sizeof(uint32_t);

        while (size >= data_.size())
        {
            if (data_[0x02] != static_cast<char>(Packet::Type::Response))
            {
                /// \todo trow exception

                break;
            }

            // if (params_->serialNumber == 0x00)
            // {
            //     params_->serialNumber = Network::Packet::valueFromBytes<uint16_t>(data_, 0x00);
            //
            //     qDebug() << Q_FUNC_INFO << "Served device SN:" << params_->serialNumber;
            // }

            const auto data = data_.mid(0x00, static_cast<int>(size));

            qDebug() << "[SOCKET] <<<" << data.toHex();

            const auto packet = Packet::fromRawData(data);

            if (packet == nullptr) return;

            emit this->incomingPacket(packet);

            data_.remove(0x00, static_cast<int>(size));

            if (data_.size() < 0x04) break;

            size = data_[0x03] + sizeof(uint32_t);
        }
    }

    void Module::connectToHost() const
    {
        qDebug() << Q_FUNC_INFO;

        this->start(params_->address, params_->networkPort);
    }

    void Module::disconnectFromHost() const
    {
        qDebug() << Q_FUNC_INFO;

        this->stop();
    }

    void Module::sendBroadcastDeviceInfoRequest() const
    {
        searcher_->writeDatagram(Packet::generateRequest(0x00, Payload::deviceInfoRequest()), QHostAddress("192.168.255.255"), params_->servicePort);
    }

    void Module::setConnectionParams(const QString& host, const QString& port) const
    {
        params_->address = host;
        params_->networkPort = port.toInt();
    }

    void Module::sendDeviceInfoRequest()
    {
        qDebug() << Q_FUNC_INFO;

        this->send(Packet::generateRequest(broadcastSN, Payload::deviceInfoRequest()));
    }

    void Module::sendSetMetersInfoRequest(const int count, const int speed, const int type, const float voltage)
    {
        qDebug() << Q_FUNC_INFO;

        this->send(Packet::generateRequest(params_->serialNumber, Payload::setMetersInfoRequest(count, speed, type, voltage)));
    }

    void Module::sendGetMetersInfoRequest()
    {
        qDebug() << Q_FUNC_INFO;

        this->send(Packet::generateRequest(params_->serialNumber, Payload::getMetersInfoRequest()));
    }

    void Module::sendSetGivenMeterRequest(const int index, const int address, const float current, const float voltage, const int constant, const int factor)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::setGivenMeterRequest(index, address, current, voltage, constant, factor)));
    }

    void Module::sendGetGivenMeterRequest(const int index)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::getGivenMeterRequest(index)));
    }

    void Module::sendAllowVoltageFlowRequest(const int allow)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::allowVoltageFlow(allow)));
    }

    void Module::sendGetMeterReadingsRequest(const int index)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::getMeterReadingsRequest(index)));
    }

    void Module::sendGetCalibratorReadingsRequest(const int reserved)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::getCalibratorReadingsRequest(reserved)));
    }

    void Module::sendSetCalibratorInfoRequest(const int type, const int constant, const float current, const float voltage)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::setCalibratorInfoRequest(type, constant, current, voltage)));
    }

    void Module::sendGetCalibratorInfoRequest(const int reserved)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::getCalibratorInfoRequest(reserved)));
    }

    void Module::sendSetHiVoltageInfoRequest(const int mode, const float volREG, const float volDAC)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::setHiVoltageInfoRequest(mode, volREG, volDAC)));
    }

    void Module::sendGetHiVoltageInfoRequest(const int reserved)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::getHiVoltageInfoRequest(reserved)));
    }

    void Module::sendSetLoVoltageInfoRequest(const int mode, const float volREG, const float volDAC)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::setLoVoltageInfoRequest(mode, volREG, volDAC)));
    }

    void Module::sendGetLoVoltageInfoRequest(const int reserved)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::getLoVoltageInfoRequest(reserved)));
    }

    void Module::sendGetStatusRequest(const int reserved)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::getStatus(reserved)));
    }

    void Module::sendAllowVoltageGenerationRequest(const int hiVoltage, const int loVoltage)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::allowVoltageGenerationRequest(hiVoltage, loVoltage)));
    }

    void Module::sendSetNetworkInfoRequest(const int host, const int port, const int mask)
    {
        this->send(Packet::generateRequest(params_->serialNumber, Payload::setNetworkInfoRequest(host, port, mask)));
    }

    void Module::onDeviceInfoReceived(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        params_->serialNumber = data->sn();

        this->sendGetHiVoltageInfoRequest();
        this->sendGetLoVoltageInfoRequest();
    }

    void Module::onConnected()
    {
        qDebug() << Q_FUNC_INFO;

        auto obj = Enercom::Config::Common::get().root()["network"].toObject();
        obj["host"] = params_->address;
        obj["port"] = params_->networkPort;

        Config::Common::get().setConfigObject("network", obj);

        this->sendDeviceInfoRequest();

        emit this->deviceConnected();
    }

    void Module::onDisconnected()
    {
        qDebug() << Q_FUNC_INFO;

        emit this->deviceDisconnected();
    }

    void Module::onReplyReceived()
    {
        qDebug() << Q_FUNC_INFO;

        data_.append(socket_->readAll());

        this->handleIncomingData();
    }

    void Module::onBroadcastReplyReceived()
    {
        QHostAddress sender;
        QByteArray datagram;
        datagram.resize(static_cast<int>(searcher_->pendingDatagramSize()));

        searcher_->readDatagram(datagram.data(), datagram.size(), &sender);

        if (const auto size = datagram[0x03] + sizeof(uint32_t); size >= datagram.size())
        {
            if (datagram[0x02] != static_cast<char>(Packet::Type::Response))
            {
                /// \todo trow exception

                return;;
            }

            const auto data = datagram.mid(0x00, static_cast<int>(size));

            qDebug() << "[SOCKET] <<<" << data.toHex();

            const auto packet = Packet::fromRawData(data);

            if (packet == nullptr) return;

            qDebug() << Q_FUNC_INFO << datagram.toHex();

            emit this->incomingBroadcastPacket(packet);
        }
    }

}
