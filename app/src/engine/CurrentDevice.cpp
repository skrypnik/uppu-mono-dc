#include "CurrentDevice.h"

#include <QDebug>

namespace Enercom
{
    CurrentDevice::CurrentDevice(QObject* parent)
        : QObject(parent)
    {

    }

    const Model::DeviceItem::Ptr& CurrentDevice::deviceInfo() const
    {
        return info_;
    }

    QVariant CurrentDevice::info() const
    {
        return QVariant::fromValue(info_.get());
    }

    void CurrentDevice::onDeviceInfoChanged(const Enercom::Model::DeviceItem::Ptr& info)
    {
        info_ = info;

        emit this->changed();
    }

}
