#pragma once

#include <QObject>

#include <model/DeviceItem.h>

namespace Enercom
{
    class CurrentDevice final : public QObject
    {
        Q_OBJECT

        /**
         * Device info
         */
        Q_PROPERTY( QVariant info READ info NOTIFY changed )

    public:
        /**
         * Constructs current device info object
         */
        explicit CurrentDevice(QObject* parent = nullptr);

        /**
         * Device info getter
         */
        [[nodiscard]] const Model::DeviceItem::Ptr& deviceInfo() const;

    private:
        /**
         * Device info getter for metaobject property
         */
        [[nodiscard]] QVariant info() const;

    signals:
        /**
         * Emit, when device info changed, used for metaobject property
         */
        void changed();

    public slots:
        /**
         * Device info changed handler
         * @param info device info
         */
        void onDeviceInfoChanged(const Enercom::Model::DeviceItem::Ptr& info);

    private:
        /**
         * Device info
         */
        Model::DeviceItem::Ptr info_;
    };

}
