#pragma once

#include <QVariant>
#include <QObject>

#include <memory>

namespace Enercom
{
    /**
    * Current device status info
    */
    class StatusInfo final : public QObject
    {
        Q_OBJECT

        /**
         * High voltage metaobject property
         */
        Q_PROPERTY( QVariant hiVoltageReady READ hiVoltageReady NOTIFY changed )

        /**
        * High voltage generation flag
        */
        Q_PROPERTY( QVariant hiVoltageGeneration READ hiVoltageGeneration NOTIFY changed )

        /**
        * High voltage
        */
        Q_PROPERTY( QVariant hiVoltage READ hiVoltage NOTIFY changed )

        /**
        * High voltage DAC
        */
        Q_PROPERTY( QVariant hiVoltageDAC READ hiVoltageDAC NOTIFY changed )

        /**
        * High voltage ADC
        */
        Q_PROPERTY( QVariant hiVoltageADC READ hiVoltageADC NOTIFY changed )

        /**
         * Low voltage ready flag
         */
        Q_PROPERTY( QVariant loVoltageReady READ loVoltageReady NOTIFY changed )

        /**
        * Low voltage generation flag
        */
        Q_PROPERTY( QVariant loVoltageGeneration READ loVoltageGeneration NOTIFY changed )

        /**
        * Low voltage
        */
        Q_PROPERTY( QVariant loVoltage READ loVoltage NOTIFY changed )

        /**
        * Low voltage DAC
        */
        Q_PROPERTY( QVariant loVoltageDAC READ loVoltageDAC NOTIFY changed )

        /**
        * Low voltage ADC
        */
        Q_PROPERTY( QVariant loVoltageADC READ loVoltageADC NOTIFY changed )

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<StatusInfo>;

    public:
        /**
         * Constructs current device status info object
         */
        explicit StatusInfo(QObject* parent = nullptr);

        /**
         * Creates params from status info response raw data
         */
        void fromRawData(const QByteArray& data);

    private:
        /**
         * High voltage ready flag
         */
        [[nodiscard]] QVariant hiVoltageReady() const;

        /**
        * High voltage generation flag
        */
        [[nodiscard]] QVariant hiVoltageGeneration() const;

        /**
        * High voltage
        */
        [[nodiscard]] QVariant hiVoltage() const;

        /**
        * High voltage DAC
        */
        [[nodiscard]] QVariant hiVoltageDAC() const;

        /**
        * High voltage ADC
        */
        [[nodiscard]] QVariant hiVoltageADC() const;

        /**
         * Low voltage ready flag
         */
        [[nodiscard]] QVariant loVoltageReady() const;

        /**
        * Low voltage generation flag
        */
        [[nodiscard]] QVariant loVoltageGeneration() const;

        /**
        * Low voltage
        */
        [[nodiscard]] QVariant loVoltage() const;

        /**
        * Low voltage DAC
        */
        [[nodiscard]] QVariant loVoltageDAC() const;

        /**
        * Low voltage ADC
        */
        [[nodiscard]] QVariant loVoltageADC() const;

    signals:
        /**
         * Emits, when params are changed
         */
        void changed();

    private:
        /**
         * High voltage ready flag
         */
        uint8_t hiVoltageReady_ {};

        /**
        * High voltage generation flag
        */
        uint8_t hiVoltageGeneration_ {};

        /**
        * High voltage
        */
        float hiVoltage_ {};

        /**
        * High voltage DAC
        */
        float hiVoltageDAC_ {};

        /**
        * High voltage ADC
        */
        float hiVoltageADC_ {};

        /**
         * Low voltage ready flag
         */
        uint8_t loVoltageReady_ {};

        /**
        * Low voltage generation flag
        */
        uint8_t loVoltageGeneration_ {};

        /**
        * Low voltage
        */
        float loVoltage_ {};

        /**
        * Low voltage DAC
        */
        float loVoltageDAC_ {};

        /**
        * Low voltage ADC
        */
        float loVoltageADC_ {};
    };

}