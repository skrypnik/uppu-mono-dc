#pragma once

#include <QObject>

namespace Enercom::Model
{
    /**
    * Device model
    */
    class DeviceModel;

    /**
     * Meter model
     */
    class MeterModel;

    /**
     * Model collection
     */
    class Module final : public QObject
    {
        Q_OBJECT

        /**
        * Device model metaobject property
        */
        Q_PROPERTY( QVariant deviceModel READ devices CONSTANT )

        /**
        * Meter model metaobject property
        */
        Q_PROPERTY( QVariant meterModel READ meters CONSTANT )

    public:
        /**
         * Constructs model collection
         * @param parent parent QObject to call safe deleter
         */
        explicit Module(QObject* parent = nullptr);

        /**
         * Device model getter
         * @return device model pointer
         */
        [[nodiscard]] const DeviceModel* deviceModel() const;

        /**
         * Meter model getter
         * @return meter model pointer
         */
        [[nodiscard]] const MeterModel* meterModel() const;

    private:
        /**
        * Device model metaobject property getter
        * @return device model pointer
        */
        [[nodiscard]] QVariant devices() const;

        /**
        * Meter model metaobject property getter
        * @return device model pointer
        */
        [[nodiscard]] QVariant meters() const;

    private:
        /**
         * Device model
         */
        DeviceModel* deviceModel_;

        /**
        * Meter model
        */
        MeterModel* meterModel_;
    };

}
