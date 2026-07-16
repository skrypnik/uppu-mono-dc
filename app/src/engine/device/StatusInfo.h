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
         * High voltage metaobject property metaobject property
         */
        Q_PROPERTY( QVariant hiVoltageReady READ hiVoltageReady NOTIFY changed )

        /**
        * High voltage generation flag metaobject property
        */
        Q_PROPERTY( QVariant hiVoltageGeneration READ hiVoltageGeneration NOTIFY changed )

        /**
        * High voltage metaobject property
        */
        Q_PROPERTY( QVariant hiVoltage READ hiVoltage NOTIFY changed )

        /**
        * High voltage DAC metaobject property
        */
        Q_PROPERTY( QVariant hiVoltageDAC READ hiVoltageDAC NOTIFY changed )

        /**
        * High voltage ADC metaobject property
        */
        Q_PROPERTY( QVariant hiVoltageADC READ hiVoltageADC NOTIFY changed )

        /**
         * Low voltage ready flag metaobject property
         */
        Q_PROPERTY( QVariant loVoltageReady READ loVoltageReady NOTIFY changed )

        /**
        * Low voltage generation flag metaobject property
        */
        Q_PROPERTY( QVariant loVoltageGeneration READ loVoltageGeneration NOTIFY changed )

        /**
        * Low voltage metaobject property
        */
        Q_PROPERTY( QVariant loVoltage READ loVoltage NOTIFY changed )

        /**
        * Low voltage DAC metaobject property
        */
        Q_PROPERTY( QVariant loVoltageDAC READ loVoltageDAC NOTIFY changed )

        /**
        * Low voltage ADC metaobject property
        */
        Q_PROPERTY( QVariant loVoltageADC READ loVoltageADC NOTIFY changed )

        /**
        * Meters power status metaobject property
        */
        Q_PROPERTY( QVariant metersPowerStatus READ metersPowerStatus NOTIFY changed )

        /**
        * Output voltage metaobject property
        */
        Q_PROPERTY( QVariant outputVoltage READ outputVoltage NOTIFY changed )

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
         * High voltage ready flag metaobject getter
         */
        [[nodiscard]] QVariant hiVoltageReady() const;

        /**
        * High voltage generation flag metaobject getter
        */
        [[nodiscard]] QVariant hiVoltageGeneration() const;

        /**
        * High voltage metaobject getter
        */
        [[nodiscard]] QVariant hiVoltage() const;

        /**
        * High voltage DAC metaobject getter
        */
        [[nodiscard]] QVariant hiVoltageDAC() const;

        /**
        * High voltage ADC metaobject getter
        */
        [[nodiscard]] QVariant hiVoltageADC() const;

        /**
         * Low voltage ready flag metaobject getter
         */
        [[nodiscard]] QVariant loVoltageReady() const;

        /**
        * Low voltage generation flag metaobject getter
        */
        [[nodiscard]] QVariant loVoltageGeneration() const;

        /**
        * Low voltage metaobject getter
        */
        [[nodiscard]] QVariant loVoltage() const;

        /**
        * Low voltage DAC metaobject getter
        */
        [[nodiscard]] QVariant loVoltageDAC() const;

        /**
        * Low voltage ADC metaobject getter
        */
        [[nodiscard]] QVariant loVoltageADC() const;

        /**
        * Low voltage ADC metaobject getter
        */
        [[nodiscard]] QVariant metersPowerStatus() const;

        /**
         * Output voltage metaobject getter
         */
        [[nodiscard]] QVariant outputVoltage() const;

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

        /**
         * Meters power status
         */
        uint8_t metersPowerStatus_ {};

        /**
         * Output voltage
         */
        float outputVoltage_ {};
    };

}