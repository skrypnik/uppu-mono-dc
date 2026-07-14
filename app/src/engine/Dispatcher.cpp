#include "Dispatcher.h"

#include <QDebug>

namespace Enercom
{
    Dispatcher::Dispatcher(QObject* parent)
        : QObject(parent)
    {

    }

    void Dispatcher::onIncomingPacket(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        if (packet->data()->type() == static_cast<uint8_t>(Network::Payload::Request::GetDeviceInfo))
        {
            emit this->deviceInfoReceived(packet);
        }

        if (packet->data()->type() == static_cast<uint8_t>(Network::Payload::Request::GetStatus))
        {
            emit this->deviceStatusInfoReceived(packet);
        }

        if (packet->data()->type() == static_cast<uint8_t>(Network::Payload::Request::GetHiVoltageInfo))
        {
            emit this->deviceHiVoltageInfoReceived(packet);
        }

        if (packet->data()->type() == static_cast<uint8_t>(Network::Payload::Request::GetLoVoltageInfo))
        {
            emit this->deviceLoVoltageInfoReceived(packet);
        }

        if (packet->data()->type() == static_cast<uint8_t>(Network::Payload::Request::GetCalibratorInfo))
        {
            emit this->deviceCalibratorInfoReceived(packet);
        }
    }

    void Dispatcher::onIncomingBroadcastPacket(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        if (packet->data()->type() != static_cast<uint8_t>(Network::Payload::Request::GetDeviceInfo)) return;

        emit this->deviceBroadcastInfoReceived(packet);
    }

}
