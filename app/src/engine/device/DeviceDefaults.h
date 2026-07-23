#pragma once

#include <QVariant>
#include <QObject>

#include <memory>

namespace Enercom
{
    /**
    * Current device calibrator info
    */
    class DeviceDefaults final : public QObject
    {
        Q_OBJECT

        /**
         * Device IP address metaobject property
         */
        Q_PROPERTY( QVariant address READ address NOTIFY changed )

        /**
         * Device netmask metaobject property
         */
        Q_PROPERTY( QVariant netmask READ netmask NOTIFY changed )

        /**
         * Device network port metaobject property
         */
        Q_PROPERTY( QVariant port READ port NOTIFY changed )

        /**
         * Device serial number metaobject property
         */
        Q_PROPERTY( QVariant serial READ serial NOTIFY changed )

        /**
         * Device MAC address metaobject property
         */
        Q_PROPERTY( QVariant mac READ mac NOTIFY changed )

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<DeviceDefaults>;

    public:
        /**
         * Constructs current device calibrator params object
         */
        explicit DeviceDefaults(QObject* parent = nullptr);

        /**
         * Creates params from calibrator info response raw data
         */
        void fromRawData(const QByteArray& data);

    private:
        /**
         * Device IP address metaobject getter
         */
        [[nodiscard]] QVariant address() const;

        /**
         * Device netmask metaobject getter
         */
        [[nodiscard]] QVariant netmask() const;

        /**
         * Device network port metaobject getter
         */
        [[nodiscard]] QVariant port() const;

        /**
         * Device serial number metaobject getter
         */
        [[nodiscard]] QVariant serial() const;

        /**
         * Device MAC address metaobject getter
         */
        [[nodiscard]] QVariant mac() const;

    signals:
        /**
        * Emits, when params are changed
        */
        void changed();

    private:
        /**
         * Device IP address
         */
        QString address_;

        /**
         * Device netmask
         */
        QString netmask_;

        /**
         * Device network port
         */
        uint16_t port_ {};

        /**
         * Device serial number
         */
        uint16_t serial_ {};

        /**
         * Device MAC address
         */
        QString mac_;
    };
}
