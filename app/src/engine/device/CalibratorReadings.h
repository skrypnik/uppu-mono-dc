#pragma once

#include <QVariant>
#include <QObject>

#include <memory>

namespace Enercom
{
    /**
    * Current device calibrator params
    */
    class CalibratorReadings final : public QObject
    {
        Q_OBJECT

        /**
         * High voltage metaobject property
         */
        Q_PROPERTY( QVariant voltage READ voltage NOTIFY changed )

        /**
         * Current metaobject property
         */
        Q_PROPERTY( QVariant current READ current NOTIFY changed )

        /**
         * Power metaobject property
         */
        Q_PROPERTY( QVariant power READ power NOTIFY changed )

        /**
         * Energy metaobject property
         */
        Q_PROPERTY( QVariant energy READ energy NOTIFY changed )

        /**
         * Pulse period metaobject property
         */
        Q_PROPERTY( QVariant pulsePeriod READ pulsePeriod NOTIFY changed )

        /**
         * Pulse count metaobject property
         */
        Q_PROPERTY( QVariant pulseCount READ pulseCount NOTIFY changed )

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<CalibratorReadings>;

    public:
        /**
         * Constructs current device calibrator params object
         */
        explicit CalibratorReadings(QObject* parent = nullptr);

        /**
         * Creates params from calibrator info response raw data
         */
        void fromRawData(const QByteArray& data);

    private:
        /**
         * High voltage value
         */
        [[nodiscard]] QVariant voltage() const;

        /**
         * Current value
         */
        [[nodiscard]] QVariant current() const;

        /**
         * Power value
         */
        [[nodiscard]] QVariant power() const;

        /**
         * Energy value
         */
        [[nodiscard]] QVariant energy() const;

        /**
         * Pulse period value
         */
        [[nodiscard]] QVariant pulsePeriod() const;

        /**
         * Pulse count value
         */
        [[nodiscard]] QVariant pulseCount() const;

    signals:
        /**
         * Emits, when params are changed
         */
        void changed();

    private:
        /**
         * High voltage value
         */
        float voltage_ {};

        /**
         * Current value
         */
        float current_ {};

        /**
         * Power value
         */
        float power_ {};

        /**
         * Energy value
         */
        float energy_ {};

        /**
         * Pulse period value
         */
        float pulsePeriod_ {};

        /**
         * Pulse count value
         */
        uint32_t pulseCount_ {};
    };

}