#include "Device.h"

#include "HiVoltageInfo.h"

#include <QDebug>

namespace Enercom
{
    Device::Device(QObject* parent)
        : QObject(parent)
        , statusInfo_(std::make_shared<StatusInfo>())
        , hiVoltageInfo_(std::make_shared<HiVoltageInfo>())
        , loVoltageInfo_(std::make_shared<LoVoltageInfo>())
        , calibratorInfo_(std::make_shared<CalibratorInfo>())
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

    QVariant Device::statusInfo() const
    {
        return QVariant::fromValue(statusInfo_.get());
    }

    QVariant Device::hiVoltageInfo() const
    {
        return QVariant::fromValue(hiVoltageInfo_.get());
    }

    QVariant Device::loVoltageInfo() const
    {
        return QVariant::fromValue(loVoltageInfo_.get());
    }

    QVariant Device::calibratorInfo() const
    {
        return QVariant::fromValue(calibratorInfo_.get());
    }

    void Device::onDeviceInfoChanged(const Enercom::Model::DeviceItem::Ptr& info)
    {
        info_ = info;

        emit this->changed();
    }

    void Device::onDeviceStatusInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        statusInfo_->fromRawData(packet->data()->data());

        emit this->changed();
    }

    void Device::onDeviceHiVoltageInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        hiVoltageInfo_->fromRawData(packet->data()->data());

        emit this->changed();
    }

    void Device::onDeviceLoVoltageInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        loVoltageInfo_->fromRawData(packet->data()->data());

        emit this->changed();
    }

    void Device::onDeviceCalibratorInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        calibratorInfo_->fromRawData(packet->data()->data());

        emit this->changed();
    }

}
