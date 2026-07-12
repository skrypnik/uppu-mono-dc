#pragma once

#include <QObject>

#include <model/DeviceItem.h>

#include <network/Packet.h>

#include "HiVoltageInfo.h"

namespace Enercom
{
    /**
    * Current device high voltage params
    */
    class HiVoltageInfo;

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
         * Device high voltage info
         */
        Q_PROPERTY( QVariant hiVoltageInfo READ hiVoltageInfo NOTIFY changed )

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
         * Device high voltage info metaobject getter
         */
        [[nodiscard]] QVariant hiVoltageInfo() const;

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
         * Device high voltage info changed handler
         * @param packet device high voltage info packet
         */
        void onDeviceHiVoltageInfoChanged(const Enercom::Network::Packet::Fields::Ptr& packet);

    private:
        /**
         * Device info
         */
        Model::DeviceItem::Ptr info_;

        /**
        * Device high voltage info
        */
        HiVoltageInfo::Ptr hiVoltageInfo_;
    };

}
