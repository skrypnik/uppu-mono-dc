#include "DeviceDefaults.h"

#include <helper/Data.h>
#include <helper/View.h>

#include <QDebug>

namespace Enercom
{
    DeviceDefaults::DeviceDefaults(QObject* parent)
    {
    }

    void DeviceDefaults::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        auto addressFromBytes = [] (const uint32_t addr)
        {
            QString value;

            int quarter = 0x04;

            while ( quarter )
            {
                auto suffix = (quarter > 0x01) ? QString(".") : QString();
                value.append(QString::number((addr >> (quarter - 0x01) * 0x08) & 0xFF) + suffix);
                quarter--;
            }

            return value;
        };

        address_ = addressFromBytes(Helper::Data::valueFromBytes<uint32_t>(data, 0x01));
        port_ = Helper::Data::valueFromBytes<uint32_t>(data, 0x05);
        netmask_ = addressFromBytes(Helper::Data::valueFromBytes<uint32_t>(data, 0x07));
        serial_ = Helper::Data::valueFromBytes<uint32_t>(data, 0x0B);
        mac_ = Helper::Data::macAddressFromBytes(data.mid(0x0D, data.size() - 0x0D));

        emit this->changed();
    }

    QVariant DeviceDefaults::address() const
    {
        return address_;
    }

    QVariant DeviceDefaults::netmask() const
    {
        return netmask_;
    }

    QVariant DeviceDefaults::port() const
    {
        return QString::number(port_);
    }

    QVariant DeviceDefaults::serial() const
    {
        return QString::number(serial_);
    }

    QVariant DeviceDefaults::mac() const
    {
        return mac_;
    }
}
