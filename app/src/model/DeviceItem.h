#pragma once

#include <QObject>
#include <QDate>

#include <memory>

namespace Enercom::Model
{
    /**
     * Device item, stores single device info
     */
    class DeviceItem final : public QObject
    {
        Q_OBJECT

        /**
         * Device serial number metaobject property
         */
        Q_PROPERTY( QVariant serial READ serial CONSTANT )

        /**
         * Device interface0 IP address metaobject property
         */
        Q_PROPERTY( QVariant address0 READ address0 CONSTANT )

        /**
         * Device interface0 IP netmask metaobject property
         */
        Q_PROPERTY( QVariant netmask0 READ netmask0 CONSTANT )

        /**
         * Device interface0 IP network port metaobject property
         */
        Q_PROPERTY( QVariant port0 READ port0 CONSTANT )

        /**
         * Device interface1 IP address metaobject property
         */
        Q_PROPERTY( QVariant address1 READ address1 CONSTANT )

        /**
         * Device interface1 IP netmask metaobject property
         */
        Q_PROPERTY( QVariant netmask1 READ netmask1 CONSTANT )

        /**
         * Device interface1 IP network port metaobject property
         */
        Q_PROPERTY( QVariant port1 READ port1 CONSTANT )

        /**
         * Firmware build date metaobject property
         */
        Q_PROPERTY( QVariant date READ date CONSTANT )

        /**
         * Firmware version metaobject property
         */
        Q_PROPERTY( QVariant version READ version CONSTANT )

        /**
         * Protocol version metaobject property
         */
        Q_PROPERTY( QVariant protocol READ protocol CONSTANT )

        /**
         * Description metaobject property
         */
        Q_PROPERTY( QVariant description READ description CONSTANT )

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<DeviceItem>;

    public:
        /**
         * Constructs device item
         * @param parent parent QObject to call safe deleter
         */
        explicit DeviceItem(QObject* parent = nullptr);

    public:
        /**
         * Creates device item from device info response raw data
         * @param data response data
         * @return device item pointer
         */
        static DeviceItem::Ptr fromRawData(const QByteArray& data);

    private:
        /**
         * Device serial number getter
         */
        [[nodiscard]] QVariant serial() const;

        /**
         * Device interface0 IP address getter
         */
        [[nodiscard]] QVariant address0() const;

        /**
         * Device interface0 IP netmask getter
         */
        [[nodiscard]] QVariant netmask0() const;

        /**
         * Device interface0 IP network port getter
         */
        [[nodiscard]] QVariant port0() const;

        /**
         * Device interface1 IP address getter
         */
        [[nodiscard]] QVariant address1() const;

        /**
         * Device interface1 IP netmask getter
         */
        [[nodiscard]] QVariant netmask1() const;

        /**
         * Device interface1 IP network port getter
         */
        [[nodiscard]] QVariant port1() const;

        /**
         * Firmware build date getter
         */
        [[nodiscard]] QVariant date() const;

        /**
         * Firmware version getter
         */
        [[nodiscard]] QVariant version() const;

        /**
         * Protocol version getter
         */
        [[nodiscard]] QVariant protocol() const;

        /**
         * Description getter
         */
        [[nodiscard]] QVariant description() const;

    private:
        /**
         * Device serial number
         */
        uint16_t serial_ {};

        /**
         * Device interface0 IP address
         */
        QString address0_;

        /**
         * Device interface0 IP netmask
         */
        QString netmask0_;

        /**
         * Device interface0 IP network port
         */
        uint16_t port0_ {};

        /**
         * Device interface1 IP address
         */
        QString address1_;

        /**
         * Device interface1 IP netmask
         */
        QString netmask1_;

        /**
         * Device interface1 IP network port
         */
        uint16_t port1_ {};

        /**
         * Firmware build date
         */
        QDate date_;

        /**
         * Firmware version
         */
        QString version_;

        /**
         * Protocol version
         */
        QString protocol_;

        /**
         * Description
         */
        QString description_;
    };

}