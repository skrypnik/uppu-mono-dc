#pragma once

#include <memory>
#include <QVariant>
#include <QObject>

namespace Enercom
{
    /**
    * Current device high voltage params
    */
    class HiVoltageInfo final : public QObject
    {
        Q_OBJECT

        /**
         * Regulator mode (0 - off, 1 - on) metaobject property
         */
        Q_PROPERTY( QVariant regulatorMode READ regulatorMode NOTIFY changed )

        /**
         * Regulator voltage metaobject property
         */
        Q_PROPERTY( QVariant regulatorVoltage READ regulatorVoltage NOTIFY changed )

        /**
         * Minimal regulator voltage metaobject property
         */
        Q_PROPERTY( QVariant regulatorVoltageMin READ regulatorVoltageMin NOTIFY changed )

        /**
         * Maximal regulator voltage metaobject property
         */
        Q_PROPERTY( QVariant regulatorVoltageMax READ regulatorVoltageMax NOTIFY changed )

        /**
         * DAC voltage metaobject property
         */
        Q_PROPERTY( QVariant dacVoltage READ dacVoltage NOTIFY changed )

        /**
         * Minimal DAC voltage metaobject property
         */
        Q_PROPERTY( QVariant dacVoltageMin READ dacVoltageMin NOTIFY changed )

        /**
         * Maximal DAC voltage metaobject property
         */
        Q_PROPERTY( QVariant dacVoltageMax READ dacVoltageMax NOTIFY changed )

        /**
         * Calibration factor metaobject property
         */
        Q_PROPERTY( QVariant calibrationFactor READ calibrationFactor NOTIFY changed )

        /**
         * Calibration offset metaobject property
         */
        Q_PROPERTY( QVariant calibrationOffset READ calibrationOffset NOTIFY changed )

        /**
         * High voltage divider ratio metaobject property
         */
        Q_PROPERTY( QVariant dividerRatio READ dividerRatio NOTIFY changed )

        /**
         * Regulator proportionality coefficient metaobject property
         */
        Q_PROPERTY( QVariant regulatorRatio READ regulatorRatio NOTIFY changed )

        /**
         * Required high voltage setting accuracy metaobject property
         */
        Q_PROPERTY( QVariant accuracy READ accuracy NOTIFY changed )

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<HiVoltageInfo>;

    public:
        /**
         * Constructs current device high voltage params object
         */
        explicit HiVoltageInfo(QObject* parent = nullptr);

        /**
         * Creates params from high voltage info response raw data
         */
        void fromRawData(const QByteArray& data);

    private:
        /**
         * Regulator mode (0 - off, 1 - on) metaobject getter
         */
        [[nodiscard]] QVariant regulatorMode() const;

        /**
         * Regulator voltage metaobject getter
         */
        [[nodiscard]] QVariant regulatorVoltage() const;

        /**
         * Minimal regulator voltage metaobject getter
         */
       [[nodiscard]] QVariant regulatorVoltageMin() const;

        /**
         * Maximal regulator voltage metaobject getter
         */
        [[nodiscard]] QVariant regulatorVoltageMax() const;

        /**
         * DAC voltage metaobject getter
         */
        [[nodiscard]] QVariant dacVoltage() const;

        /**
         * Minimal DAC voltage metaobject getter
         */
        [[nodiscard]] QVariant dacVoltageMin() const;

        /**
         * Maximal DAC voltage metaobject getter
         */
        [[nodiscard]] QVariant dacVoltageMax() const;

        /**
         * Calibration factor metaobject getter
         */
        [[nodiscard]] QVariant calibrationFactor() const;

        /**
         * Calibration offset metaobject getter
         */
        [[nodiscard]] QVariant calibrationOffset() const;

        /**
         * High voltage divider ratio metaobject getter
         */
        [[nodiscard]] QVariant dividerRatio() const;

        /**
         * Regulator proportionality coefficient metaobject getter
         */
        [[nodiscard]] QVariant regulatorRatio() const;

        /**
         * Required high voltage setting accuracy metaobject getter
         */
        [[nodiscard]] QVariant accuracy() const;

    signals:
        /**
         * Emits, when params are changed
         */
        void changed();

    private:
        /**
         * Regulator mode (0 - off, 1 - on)
         */
        uint8_t regulatorMode_{};

        /**
         * Regulator voltage
         */
        float regulatorVoltage_{};

        /**
         * Minimal regulator voltage
         */
        float regulatorVoltageMin_{};

        /**
         * Maximal regulator voltage
         */
        float regulatorVoltageMax_{};

        /**
         * DAC voltage
         */
        float dacVoltage_{};

        /**
         * Minimal DAC voltage
         */
        float dacVoltageMin_{};

        /**
         * Maximal DAC voltage
         */
        float dacVoltageMax_{};

        /**
         * Calibration factor
         */
        float calibrationFactor_{};

        /**
         * Calibration offset
         */
        float calibrationOffset_{};

        /**
         * High voltage divider ratio
         */
        float dividerRatio_{};

        /**
         * Regulator proportionality coefficient
         */
        uint32_t regulatorRatio_{};

        /**
         * Required high voltage setting accuracy
         */
        float accuracy_{};
    };

}
