#pragma once

#include <QVariant>
#include <QObject>

#include <memory>

namespace Enercom
{
    /**
    * Current device calibrator info
    */
    class CalibratorInfo final : public QObject
    {
        Q_OBJECT

        /**
         * Calibrator constant metaobject property
         */
        Q_PROPERTY( QVariant constant READ constant NOTIFY changed )

        /**
         * Current metaobject property
         */
        Q_PROPERTY( QVariant current READ current NOTIFY changed )

        /**
         * Voltage metaobject property
         */
        Q_PROPERTY( QVariant voltage READ voltage NOTIFY changed )

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<CalibratorInfo>;

    public:
        /**
         * Constructs current device calibrator params object
         */
        explicit CalibratorInfo(QObject* parent = nullptr);

        /**
         * Creates params from calibrator info response raw data
         */
        void fromRawData(const QByteArray& data);

    private:
        /**
         * Calibrator constant value metaobject getter
         */
        [[nodiscard]] QVariant constant() const;

        /**
         * Current value metaobject getter
         */
        [[nodiscard]] QVariant current() const;

        /**
         * High voltage value metaobject getter
         */
        [[nodiscard]] QVariant voltage() const;

    signals:
        /**
        * Emits, when params are changed
        */
        void changed();

    private:
        /**
         * Calibrator constant
         */
        uint32_t constant_ {};

        /**
         * Current value
         */
        float current_ {};

        /**
         * Voltage value
         */
        float voltage_ {};
    };
}