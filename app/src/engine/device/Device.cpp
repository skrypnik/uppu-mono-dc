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
        , defaults_(std::make_shared<DeviceDefaults>())
        , calibratorInfo_(std::make_shared<CalibratorInfo>())
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

    QVariant Device::defaults() const
    {
        return QVariant::fromValue(defaults_.get());
    }

    QVariant Device::calibratorInfo() const
    {
        return QVariant::fromValue(calibratorInfo_.get());
    }

    QVariant Device::calibratorReadings() const
    {
        return QVariant::fromValue(calibratorReadings_.get());
    }

    const Model::DeviceItem::Ptr& Device::infoPtr() const
    {
        return info_;
    }

    const StatusInfo::Ptr& Device::statusInfoPtr() const
    {
        return statusInfo_;
    }

    const MetersInfo::Ptr& Device::metersInfoPtr() const
    {
        return metersInfo_;
    }

    const HiVoltageInfo::Ptr& Device::hiVoltageInfoPtr() const
    {
        return hiVoltageInfo_;
    }

    const LoVoltageInfo::Ptr& Device::loVoltageInfoPtr() const
    {
        return loVoltageInfo_;
    }

    const DeviceDefaults::Ptr& Device::defaultsPtr() const
    {
        return  defaults_;
    }

    const CalibratorInfo::Ptr& Device::calibratorInfoPtr() const
    {
        return calibratorInfo_;
    }

    const CalibratorReadings::Ptr& Device::calibratorReadingsPtr() const
    {
        return calibratorReadings_;
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

    void Device::onDeviceDefaultsChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        defaults_->fromRawData(packet->data()->data());

        emit this->changed();
    }

    void Device::onDeviceCalibratorInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        calibratorInfo_->fromRawData(packet->data()->data());

        emit this->changed();
    }

    void Device::onDeviceCalibratorReadingsChanged(const Enercom::Network::Packet::Fields::Ptr& packet)
    {
        calibratorReadings_->fromRawData(packet->data()->data());

        emit this->changed();
    }

}
