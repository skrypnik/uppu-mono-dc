#include "Device.h"

#include <QDebug>

namespace Enercom
{
    Device::Device(QObject* parent)
        : QObject(parent)
        , statusInfo_(std::make_shared<StatusInfo>())
        , metersInfo_(std::make_shared<MetersInfo>())
        , hiVoltageInfo_(std::make_shared<HiVoltageInfo>())
        , loVoltageInfo_(std::make_shared<LoVoltageInfo>())
        , calibratorReadings_(std::make_shared<CalibratorReadings>())
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

    QVariant Device::metersInfo() const
    {
        return QVariant::fromValue(metersInfo_.get());
    }

    QVariant Device::hiVoltageInfo() const
    {
        return QVariant::fromValue(hiVoltageInfo_.get());
    }

    QVariant Device::loVoltageInfo() const
    {
        return QVariant::fromValue(loVoltageInfo_.get());
    }

    QVariant Device::calibratorReadings() const
    {
        return QVariant::fromValue(calibratorReadings_.get());
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

    void Device::onDeviceMetersInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        metersInfo_->fromRawData(packet->data()->data());

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

    void Device::onDeviceCalibratorReadingsChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        calibratorReadings_->fromRawData(packet->data()->data());

        emit this->changed();
    }

}
