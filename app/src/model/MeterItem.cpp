#include "MeterItem.h"

#include <QAbstractListModel>

#include <network/Packet.h>

#include <helper/Data.h>
#include <helper/View.h>

namespace Enercom::Model
{
    MeterItem::MeterItem(QObject* parent)
        : QObject(parent)
    {

    }

    MeterItem::Ptr MeterItem::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        auto item = std::make_shared<MeterItem>();

        item->index_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x01);
        item->address_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x02);
        item->current_ = Helper::Data::valueFromBytes<float>(data, 0x03);
        item->voltage_ = Helper::Data::valueFromBytes<float>(data, 0x07);
        item->constant_ = Helper::Data::valueFromBytes<uint32_t>(data, 0x0B);
        item->pulse_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x0F);

        return item;
    }

    QVariant MeterItem::index() const
    {
        return QString::number(index_);
    }

    QVariant MeterItem::address() const
    {
        return QString::number(address_);
    }

    QVariant MeterItem::current() const
    {
        return Helper::View::normalizedFloat(current_);
    }

    QVariant MeterItem::voltage() const
    {
        return Helper::View::normalizedFloat(voltage_);
    }

    QVariant MeterItem::constant() const
    {
        return QString::number(constant_);
    }

    QVariant MeterItem::pulse() const
    {
        return pulse_;
    }

}
