#include "DeviceItem.h"

#include <QAbstractListModel>

#include <network/Packet.h>

namespace Enercom::Model
{
    DeviceItem::DeviceItem(QObject* parent)
        : QObject(parent)
    {

    }

    DeviceItem::Ptr DeviceItem::fromRawData(const QByteArray& data)
    {
        auto item = std::make_shared<DeviceItem>();

        auto addressFromBytes = [] (uint32_t addr)
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

        item->address0_ = addressFromBytes(Network::Packet::valueFromBytes<uint32_t>(data, 0x01));
        item->port0_ = Network::Packet::valueFromBytes<uint16_t>(data, 0x05);
        item->netmask0_ = addressFromBytes(Network::Packet::valueFromBytes<uint32_t>(data, 0x07));

        item->address1_ = addressFromBytes(Network::Packet::valueFromBytes<uint32_t>(data, 0x0B));
        item->port1_ = Network::Packet::valueFromBytes<uint16_t>(data, 0x0F);
        item->netmask1_ = addressFromBytes(Network::Packet::valueFromBytes<uint32_t>(data, 0x11));

        item->serial_ = Network::Packet::valueFromBytes<uint16_t>(data, 0x15);

        item->version_.append(QString::number(static_cast<uint8_t>(data[0x1A])) + QString("."));
        item->version_.append(QString::number(static_cast<uint8_t>(data[0x19])) + QString("."));
        item->version_.append(QString::number(static_cast<uint8_t>(data[0x18])) + QString("."));
        item->version_.append(QString::number(static_cast<uint8_t>(data[0x17])));

        item->date_.setDate(Network::Packet::valueFromBytes<uint16_t>(data, 0x1B), Network::Packet::valueFromBytes<uint8_t>(data, 0x1D), Network::Packet::valueFromBytes<uint8_t>(data, 0x1E));
        item->protocol_.append(QString::number(data[0x1F]) + QString("."));
        item->protocol_.append(QString::number(data[0x20]) + QString("."));
        item->protocol_.append(QString::number(data[0x21]));

        item->description_ = data.mid(0x22, data.size() - 0x22);

        return item;
    }

    QVariant DeviceItem::serial() const
    {
        return serial_;
    }

    QVariant DeviceItem::address0() const
    {
        return address0_;
    }

    QVariant DeviceItem::netmask0() const
    {
        return netmask0_;
    }

    QVariant DeviceItem::port0() const
    {
        return port0_;
    }

    QVariant DeviceItem::address1() const
    {
        return address1_;
    }

    QVariant DeviceItem::netmask1() const
    {
        return netmask1_;
    }

    QVariant DeviceItem::port1() const
    {
        return port1_;
    }

    QVariant DeviceItem::date() const
    {
        return date_.toString("dd.MM.yyyy");
    }

    QVariant DeviceItem::version() const
    {
        return version_;
    }

    QVariant DeviceItem::protocol() const
    {
        return protocol_;
    }

    QVariant DeviceItem::description() const
    {
        return description_;
    }
}
