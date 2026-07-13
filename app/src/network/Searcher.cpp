#include "Searcher.h"

#include <config/Common.h>

namespace Enercom::Network
{
    Searcher::Searcher(QObject* parent)
        : QTimer(parent)
        , socket_(new QUdpSocket(this))
    {

    }

    void Searcher::initialize()
    {
        this->setInterval(Config::Common::get().root()["service"]["interval"].toInt());

        const auto port = Config::Common::get().root()["service"]["port"].toInt();

        socket_->bind(QHostAddress::Any, port);

        QObject::connect(this, &QTimer::timeout, this, &Searcher::onSendBroadcastRequest);

        QObject::connect(socket_, &QUdpSocket::readyRead, this, &Searcher::onReceiveBroadcastRequest);
    }

    void Searcher::onSendBroadcastRequest() const
    {
        const auto subnet = Config::Common::get().root()["service"]["subnet"].toString();
        const auto serial = Config::Common::get().root()["service"]["serial"].toInt();
        const auto port = Config::Common::get().root()["service"]["port"].toInt();

        socket_->writeDatagram(Packet::generateRequest(serial, Payload::deviceInfoRequest()), QHostAddress(subnet), port);
    }

    void Searcher::onReceiveBroadcastRequest()
    {
        QHostAddress sender;
        QByteArray datagram;
        datagram.resize(static_cast<int>(socket_->pendingDatagramSize()));

        socket_->readDatagram(datagram.data(), datagram.size(), &sender);

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
