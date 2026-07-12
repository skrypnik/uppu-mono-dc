#include "Device.h"

#include "HiVoltageInfo.h"

#include <QDebug>

namespace Enercom
{
    Device::Device(QObject* parent)
        : QObject(parent)
    {

    }

    const Model::DeviceItem::Ptr& Device::deviceInfo() const
    {
        return info_;
    }

    QVariant Device::info() const
    {
        return QVariant::fromValue(info_.get());
    }

    QVariant Device::hiVoltageInfo() const
    {
        return QVariant::fromValue(hiVoltageInfo_.get());
    }

    void Device::onDeviceInfoChanged(const Enercom::Model::DeviceItem::Ptr& info)
    {
        info_ = info;

        emit this->changed();
    }

    void Device::onDeviceHiVoltageInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        hiVoltageInfo_->fromRawData(packet->data()->data());

        emit this->changed();
    }

}
