#include "Module.h"

#include <config/Common.h>

#include <QTcpSocket>

#include "Packet.h"

namespace Enercom::Network
{
    class ConnectionParams
    {
        friend class Module;

        /**
        * Device address or hostname
        */
        QString host = Enercom::Config::Common::get().root()["network"]["host"].toString();

        /**
        * Device network port. Defaults: 63500 - common port (can be changed), 57555 - service port (constant)
        */
        quint16 port = Enercom::Config::Common::get().root()["network"]["host"].toInt();
    };

    Module::Module(QObject* parent)
        : QObject(parent)
          , params_(new ConnectionParams)
          , socket_(new QTcpSocket(this))
    {
        QObject::connect(socket_, &QTcpSocket::connected,    this, &Module::onConnected);
        QObject::connect(socket_, &QTcpSocket::disconnected, this, &Module::onDisconnected);
        QObject::connect(socket_, &QTcpSocket::readyRead,    this, &Module::onReplyReceived);

        serials_.insert(0x00); /// bradcast serial number
    }

    Module::~Module()
    {
        delete params_;
    }

    void Module::start(const QString& host, const uint16_t port) const
    {
        qDebug() << Q_FUNC_INFO;

        params_->host = host;
        params_->port = port;

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
            /// \todo
            // if (serials_.find(data_.mid(0x00, 0x02).toShort()) == serials_.end())
            // {
            //     /// \todo trow exception
            //
            //     break;
            // }

            if (data_[0x02] != static_cast<char>(Packet::Type::Response))
            {
                /// \todo trow exception

                break;
            }

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

        this->start(params_->host, params_->port);
    }

    void Module::disconnectFromHost() const
    {
        qDebug() << Q_FUNC_INFO;

        this->stop();
    }

    void Module::setConnectionParams(const QString& host, const QString& port) const
    {
        params_->host = host;
        params_->port = port.toInt();
    }

    void Module::sendDeviceInfoRequest()
    {
        qDebug() << Q_FUNC_INFO;

        this->send(Packet::generateRequest(0x00, Payload::deviceInfoRequest()));
    }

    void Module::sendSetMetersInfoRequest(const int count, const int speed, const int type, const float voltage)
    {
        qDebug() << Q_FUNC_INFO;

        this->send(Packet::generateRequest(0x3039, Payload::setMetersInfoRequest(count, speed, type, voltage)));
    }

    void Module::sendGetMetersInfoRequest()
    {
        qDebug() << Q_FUNC_INFO;

        this->send(Packet::generateRequest(0x3039, Payload::getMetersInfoRequest()));
    }

    void Module::sendSetGivenMeterRequest(const int index, const int address, const float current, const float voltage, const int constant, const int factor)
    {
        this->send(Packet::generateRequest(0x3039, Payload::setGivenMeterRequest(index, address, current, voltage, constant, factor)));
    }

    void Module::sendGetGivenMeterRequest(const int index)
    {
        this->send(Packet::generateRequest(0x3039, Payload::getGivenMeterRequest(index)));
    }

    void Module::sendAllowVoltageFlowRequest(const int allow)
    {
        this->send(Packet::generateRequest(0x3039, Payload::allowVoltageFlow(allow)));
    }

    void Module::sendGetMeterReadingsRequest(const int index)
    {
        this->send(Packet::generateRequest(0x3039, Payload::getMeterReadingsRequest(index)));
    }

    void Module::sendGetCalibratorReadingsRequest(const int reserved)
    {
        this->send(Packet::generateRequest(0x3039, Payload::getCalibratorReadingsRequest(reserved)));
    }

    void Module::sendSetCalibratorInfoRequest(const int type, const int constant, const float current, const float voltage)
    {
        this->send(Packet::generateRequest(0x3039, Payload::setCalibratorInfoRequest(type, constant, current, voltage)));
    }

    void Module::sendGetCalibratorInfoRequest(const int reserved)
    {
        this->send(Packet::generateRequest(0x3039, Payload::getCalibratorInfoRequest(reserved)));
    }

    void Module::sendSetHiVoltageInfoRequest(const int mode, const float volREG, const float volDAC)
    {
        this->send(Packet::generateRequest(0x3039, Payload::setHiVoltageInfoRequest(mode, volREG, volDAC)));
    }

    void Module::sendGetHiVoltageInfoRequest(const int reserved)
    {
        this->send(Packet::generateRequest(0x3039, Payload::getHiVoltageInfoRequest(reserved)));
    }

    void Module::sendSetLoVoltageInfoRequest(const int mode, const float volREG, const float volDAC)
    {
        this->send(Packet::generateRequest(0x3039, Payload::setLoVoltageInfoRequest(mode, volREG, volDAC)));
    }

    void Module::sendGetLoVoltageInfoRequest(const int reserved)
    {
        this->send(Packet::generateRequest(0x3039, Payload::getLoVoltageInfoRequest(reserved)));
    }

    void Module::sendGetStatusRequest(const int reserved)
    {
        this->send(Packet::generateRequest(0x3039, Payload::getStatus(reserved)));
    }

    void Module::sendAllowVoltageGenerationRequest(const int hiVoltage, const int loVoltage)
    {
        this->send(Packet::generateRequest(0x3039, Payload::allowVoltageGenerationRequest(hiVoltage, loVoltage)));
    }

    void Module::sendSetNetworkInfoRequest(const int host, const int port, const int mask)
    {
        this->send(Packet::generateRequest(0x3039, Payload::setNetworkInfoRequest(host, port, mask)));
    }

    void Module::onConnected()
    {
        qDebug() << Q_FUNC_INFO;

        auto obj = Enercom::Config::Common::get().root()["network"].toObject();
        obj["host"] = params_->host;
        obj["port"] = params_->port;

        Config::Common::get().setConfigObject("network", obj);

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

}
