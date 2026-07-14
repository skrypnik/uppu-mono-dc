#pragma once

#include <model/DeviceItem.h>

#include <network/Packet.h>

#include "StatusInfo.h"
#include "HiVoltageInfo.h"
#include "LoVoltageInfo.h"
#include "CalibratorInfo.h"

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
         * Device high voltage info
         */
        Q_PROPERTY( QVariant hiVoltageInfo READ hiVoltageInfo NOTIFY changed )

        /**
         * Device low voltage info
         */
        Q_PROPERTY( QVariant loVoltageInfo READ loVoltageInfo NOTIFY changed )

        /**
         * Device calibrator info
         */
        Q_PROPERTY( QVariant calibratorInfo READ calibratorInfo NOTIFY changed )

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
         * Device high voltage info metaobject getter
         */
        [[nodiscard]] QVariant hiVoltageInfo() const;

        /**
         * Device low voltage info metaobject getter
         */
        [[nodiscard]] QVariant loVoltageInfo() const;

        /**
         * Device calibrator info metaobject getter
         */
        [[nodiscard]] QVariant calibratorInfo() const;

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
         * Device info changed handler
         * @param packet device status info packet
         */
        void onDeviceStatusInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

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
         * Device calibrator info changed handler
         * @param packet device calibrator info packet
         */
        void onDeviceCalibratorInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

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
        * Device high voltage info
        */
        HiVoltageInfo::Ptr hiVoltageInfo_;

        /**
        * Device high voltage info
        */
        LoVoltageInfo::Ptr loVoltageInfo_;

        /**
         * Device calibrator info
         */
        CalibratorInfo::Ptr calibratorInfo_;
    };

}
