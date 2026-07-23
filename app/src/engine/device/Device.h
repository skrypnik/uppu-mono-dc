#pragma once

#include <model/DeviceItem.h>

#include <network/Packet.h>

#include "StatusInfo.h"
#include "MetersInfo.h"
#include "HiVoltageInfo.h"
#include "LoVoltageInfo.h"
#include "DeviceDefaults.h"
#include "CalibratorInfo.h"
#include "CalibratorReadings.h"

namespace Enercom
{
    /**
     * Current device params
     */
    class Device final : public QObject
    {
        Q_OBJECT

        /**
         * Device info
         */
        Q_PROPERTY( QVariant info READ info NOTIFY changed )

        /**
         * Device status info
         */
        Q_PROPERTY( QVariant statusInfo READ statusInfo NOTIFY changed )

        /**
         * Meters info
         */
        Q_PROPERTY( QVariant metersInfo READ metersInfo NOTIFY changed )

        /**
         * Device high voltage info
         */
        Q_PROPERTY( QVariant hiVoltageInfo READ hiVoltageInfo NOTIFY changed )

        /**
         * Device low voltage info
         */
        Q_PROPERTY( QVariant loVoltageInfo READ loVoltageInfo NOTIFY changed )

        /**
         * Device defaults
         */
        Q_PROPERTY( QVariant defaults READ defaults NOTIFY changed )

        /**
         * Device calibrator info
         */
        Q_PROPERTY( QVariant calibratorInfo READ calibratorInfo NOTIFY changed )

        /**
         * Device calibrator readings
         */
        Q_PROPERTY( QVariant calibratorReadings READ calibratorReadings NOTIFY changed )

    public:
        /**
         * Constructs current device info object
         */
        explicit Device(QObject* parent = nullptr);

        /**
         * Device info getter
         */
        [[nodiscard]] const Model::DeviceItem::Ptr& deviceInfo() const;

    private:
        /**
         * Device info metaobject getter
         */
        [[nodiscard]] QVariant info() const;

        /**
         * Device status info metaobject getter
         */
        [[nodiscard]] QVariant statusInfo() const;

        /**
         * Meters info metaobject getter
         */
        [[nodiscard]] QVariant metersInfo() const;

        /**
         * Device high voltage info metaobject getter
         */
        [[nodiscard]] QVariant hiVoltageInfo() const;

        /**
         * Device low voltage info metaobject getter
         */
        [[nodiscard]] QVariant loVoltageInfo() const;

        /**
         * Device defaults metaobject getter
         */
        [[nodiscard]] QVariant defaults() const;

        /**
         * Device calibrator info metaobject getter
         */
        [[nodiscard]] QVariant calibratorInfo() const;

        /**
         * Device calibrator readings metaobject getter
         */
        [[nodiscard]] QVariant calibratorReadings() const;

    public:
        /**
         * Device info getter
         */
        [[nodiscard]] const Model::DeviceItem::Ptr& infoPtr() const;

        /**
         * Device status info getter
         */
        [[nodiscard]] const StatusInfo::Ptr& statusInfoPtr() const;

        /**
         * Meters info getter
         */
        [[nodiscard]] const MetersInfo::Ptr& metersInfoPtr() const;

        /**
        * Device high voltage info getter
        */
        [[nodiscard]] const HiVoltageInfo::Ptr& hiVoltageInfoPtr() const;

        /**
        * Device high voltage info getter
        */
        [[nodiscard]] const LoVoltageInfo::Ptr& loVoltageInfoPtr() const;

        /**
         * Device defaults info getter
         */
        [[nodiscard]] const DeviceDefaults::Ptr& defaultsPtr() const;

        /**
         * Device calibrator info getter
         */
        [[nodiscard]] const CalibratorInfo::Ptr& calibratorInfoPtr() const;

        /**
         * Device calibrator readings getter
         */
        [[nodiscard]] const CalibratorReadings::Ptr& calibratorReadingsPtr() const;

    signals:
        /**
         * Emit, when device info changed, used for metaobject property
         */
        void changed();

    public slots:
        /**
         * Device info changed handler
         * @param info device info
         */
        void onDeviceInfoChanged(const Enercom::Model::DeviceItem::Ptr& info);

        /**
         * Device status info changed handler
         * @param packet device status info packet
         */
        void onDeviceStatusInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
         * Device meters info changed handler
         * @param packet device meters info packet
         */
        void onDeviceMetersInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
         * Device high voltage info changed handler
         * @param packet device high voltage info packet
         */
        void onDeviceHiVoltageInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
         * Device low voltage info changed handler
         * @param packet device low voltage info packet
         */
        void onDeviceLoVoltageInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
         * Device defaults changed handler
         * @param packet device low voltage info packet
         */
        void onDeviceDefaultsChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
         * Device calibrator info changed handler
         * @param packet device calibrator info packet
         */
        void onDeviceCalibratorInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
         * Device calibrator readings changed handler
         * @param packet device calibrator info packet
         */
        void onDeviceCalibratorReadingsChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

    private:
        /**
         * Device info
         */
        Model::DeviceItem::Ptr info_;

        /**
         * Device status info
         */
        StatusInfo::Ptr statusInfo_;

        /**
         * Meters info
         */
        MetersInfo::Ptr metersInfo_;

        /**
        * Device high voltage info
        */
        HiVoltageInfo::Ptr hiVoltageInfo_;

        /**
        * Device high voltage info
        */
        LoVoltageInfo::Ptr loVoltageInfo_;

        /**
         * Device defaults
         */
        DeviceDefaults::Ptr defaults_;

        /**
         * Device calibrator info
         */
        CalibratorInfo::Ptr calibratorInfo_;

        /**
         * Device calibrator readings
         */
        CalibratorReadings::Ptr calibratorReadings_;
    };

}
