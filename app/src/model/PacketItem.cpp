#include "PacketItem.h"

#include <QVariant>

namespace Enercom::Model
{
    PacketItem::PacketItem(Network::Packet::Fields::Ptr data, QObject* parent)
        : QObject(parent)
        , data_(std::move(data))
    {
        const auto sn = data_->sn();
        sn_ = DataView::toHexView(QByteArray::fromRawData(reinterpret_cast<const char*>(&sn), sizeof(sn)));

        const auto crc = data_->crc();
        crc_ = DataView::toHexView(QByteArray::fromRawData(reinterpret_cast<const char*>(&crc), sizeof(crc)));

        {
            const auto type = data_->type();
            const auto typeBytes = QByteArray::fromRawData(reinterpret_cast<const char*>(&type), sizeof(type));

            const auto size = data_->size();
            const auto sizeBytes = QByteArray::fromRawData(reinterpret_cast<const char*>(&size), sizeof(size));

            const auto dataBytes = data_->data()->bytes();

            packet_ = DataView::create(typeBytes, sizeBytes, dataBytes);
        }

        {
            const auto type = data_->data()->type();
            const auto typeBytes = QByteArray::fromRawData(reinterpret_cast<const char*>(&type), sizeof(type));

            const auto size = data_->data()->size();
            const auto sizeBytes = QByteArray::fromRawData(reinterpret_cast<const char*>(&size), sizeof(size));

            const auto dataBytes = data_->data()->data();

            payload_ = DataView::create(typeBytes, sizeBytes, dataBytes);
        }
    }

    const QStringList& PacketItem::sn() const
    {
        return sn_;
    }

    const QStringList& PacketItem::crc() const
    {
        return crc_;
    }

    QVariant PacketItem::packet() const
    {
        return QVariant::fromValue(packet_.get());
    }

    QVariant PacketItem::payload() const
    {
        return QVariant::fromValue(payload_.get());
    }

}
