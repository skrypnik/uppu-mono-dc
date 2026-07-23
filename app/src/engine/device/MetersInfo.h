#pragma once

#include <QVariant>
#include <QObject>

#include <memory>

namespace Enercom
{
    /**
    * Meters info
    */
    class MetersInfo final : public QObject
    {
        Q_OBJECT

        /**
         * Meters count metaobject property
         */
        Q_PROPERTY( QVariant count READ count NOTIFY changed )

        /**
         * UART baud rate metaobject property
         */
        Q_PROPERTY( QVariant baudRate READ baudRate NOTIFY changed )

        /**
         * Input kind metaobject property
         */
        Q_PROPERTY( QVariant inputKind READ inputKind NOTIFY changed )

        /**
         * Input voltage metaobject property
         */
        Q_PROPERTY( QVariant inputVoltage READ inputVoltage NOTIFY changed )

        /**
         * Output voltage metaobject property
         */
        Q_PROPERTY( QVariant outputVoltage READ outputVoltage NOTIFY changed )

        /**
         * Current baud rate index in available speed list metaobject property
         */
        Q_PROPERTY( QVariant baudRateIndex READ baudRateIndex NOTIFY changed )

        /**
         * List of available UART speed values metaobject property
         */
        Q_PROPERTY( QVariant availableSpeedValues READ availableSpeedValues NOTIFY changed )

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<MetersInfo>;

    private:
        /**
         * List of available UART speed values
         */
        const QStringList availableSpeedValues_;

    public:
        /**
         * Constructs meters info object
         */
        explicit MetersInfo(QObject* parent = nullptr);

        /**
         * Creates params from meters info response raw data
         */
        void fromRawData(const QByteArray& data);

    private:
        /**
         * Meters count metaobject getter
         */
        [[nodiscard]] QVariant count() const;

        /**
         * UART baud rate metaobject getter
         */
        [[nodiscard]] QVariant baudRate() const;

        /**
         * Input kind metaobject getter
         */
        [[nodiscard]] QVariant inputKind() const;

        /**
         * Input voltage metaobject getter
         */
        [[nodiscard]] QVariant inputVoltage() const;

        /**
         * Output voltage metaobject getter
         */
        [[nodiscard]] QVariant outputVoltage() const;

        /**
         * Current baud rate index in available speed list metaobject getter
         */
        [[nodiscard]] QVariant baudRateIndex() const;

        /**
         * List of available UART speed values metaobject getter
         */
        [[nodiscard]] QVariant availableSpeedValues() const;

    signals:
        /**
         * Emits, when params are changed
         */
        void changed();

        /**
         * Emits, when meters count are changed
         */
        void clearMeterModel();

        /**
         * Emits when each meter request neaded
         * @param count meters count
         */
        void requestEachMeterInfo(int count);

    private:
        /**
         * Meters count
         */
        uint8_t count_ {};

        /**
         * UART baud rate
         */
        uint32_t baudRate_ {};

        /**
         * Input kind (0-UVS, 1-pulse input)
         */
        uint8_t inputKind_ {};

        /**
         * Input voltage
         */
        float inputVoltage_ {};

        /**
         * Output voltage
         */
        float outputVoltage_ {};
    };

}