#pragma once

#include <QObject>

namespace Enercom::Model
{
    /**
    * Device model
    */
    class DeviceModel;

    /**
     * Model collection
     */
    class Module final : public QObject
    {
        Q_OBJECT

        /**
        * Device model
        */
        Q_PROPERTY( QVariant deviceModel READ devices CONSTANT )

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

    private:
        /**
        * Device model metaobject property getter
        * @return device model pointer
        */
        [[nodiscard]] QVariant devices() const;

    private:
        /**
         * Device model
         */
        DeviceModel* deviceModel_;
    };

}
