#include "Searcher.h"

#include "Packet.h"

#include <QNetworkDatagram>
#include <QUdpSocket>

#include <QDebug>

namespace Enercom::Network
{
    Searcher::Searcher(QObject* parent)
        : QObject(parent)
        , socket_(new QUdpSocket(this))
    {
        QObject::connect(socket_, &QUdpSocket::readyRead, this, &Searcher::onDataAvailable);
    }

    void Searcher::startSearch(const uint16_t port) const
    {
        socket_->bind(QHostAddress::AnyIPv4, port);

        socket_->writeDatagram(Packet::generateRequest(0x00, Payload::deviceInfoRequest()), QHostAddress("192.168.138.255"), port);
    }

    void Searcher::onDataAvailable() const
    {
        while (socket_->hasPendingDatagrams()) {

             qDebug() << Q_FUNC_INFO << socket_->receiveDatagram().data().toHex();
        }
    }

}
