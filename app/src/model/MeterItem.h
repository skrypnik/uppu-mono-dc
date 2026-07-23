#pragma once

#include <QObject>
#include <QDate>

#include <memory>

namespace Enercom::Model
{
    /**
     * Meter item, stores single meter info
     */
    class MeterItem final : public QObject
    {
        Q_OBJECT

        /**
         * Meter index metaobject property
         */
        Q_PROPERTY( QVariant index READ index CONSTANT )

        /**
         * Meter address metaobject property
         */
        Q_PROPERTY( QVariant address READ address CONSTANT )

        /**
         * Meter current metaobject property
         */
        Q_PROPERTY( QVariant current READ current CONSTANT )

        /**
         * Meter voltage metaobject property
         */
        Q_PROPERTY( QVariant voltage READ voltage CONSTANT )

        /**
         * Meter constant metaobject property
         */
        Q_PROPERTY( QVariant constant READ constant CONSTANT )

        /**
         * Meter pulse metaobject property
         */
        Q_PROPERTY( QVariant pulse READ pulse CONSTANT )

    public:
        /**
         * For easy usage
         */
        friend class MeterModel;

        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<MeterItem>;

    public:
        /**
         * Constructs meter item
         * @param parent parent QObject to call safe deleter
         */
        explicit MeterItem(QObject* parent = nullptr);

    public:
        /**
         * Creates meter item from meter info response raw data
         * @param data response data
         * @return device item pointer
         */
        static MeterItem::Ptr fromRawData(const QByteArray& data);

    private:
        /**
         * Meter index metaobject getter
         */
        [[nodiscard]] QVariant index() const;

        /**
         * Meter address metaobject getter
         */
        [[nodiscard]] QVariant address() const;

        /**
         * Meter current metaobject getter
         */
        [[nodiscard]] QVariant current() const;

        /**
         * Meter voltage metaobject getter
         */
        [[nodiscard]] QVariant voltage() const;

        /**
         * Meter constant metaobject getter
         */
        [[nodiscard]] QVariant constant() const;

        /**
         * Meter pulse metaobject getter
         */
        [[nodiscard]] QVariant pulse() const;

    private:
        /**
         * Meter index
         */
        uint8_t index_ {};

        /**
         * Meter MODBUS address
         */
        uint8_t address_ {};

        /**
         * Meter nominal current
         */
        float current_ {};

        /**
         * Meter voltage
         */
        float voltage_ {};

        /**
         * Meter constant
         */
        uint32_t constant_ {};

        /**
        * Meter pulse mode
        */
        uint8_t pulse_ {};
    };

}