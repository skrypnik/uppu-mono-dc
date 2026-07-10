#include "Dispatcher.h"

namespace Enercom
{
    Dispatcher::Dispatcher(QObject* parent)
        : QObject(parent)
    {

    }

    void Dispatcher::onIncomingData(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        if (data->type() == static_cast<uint8_t>(Network::Payload::Request::GetDeviceInfo))
        {
            emit this->deviceInfoReceived(data);
        }
    }
}
