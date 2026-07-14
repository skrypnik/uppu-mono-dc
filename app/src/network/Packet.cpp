#include "Packet.h"

#include <helper/Data.h>

#include <QDebug>

namespace Enercom::Network
{
    Packet::Fields::Fields()
        : data_(std::make_shared<Payload::Fields>())
    {
    }

    uint16_t Packet::Fields::sn() const
    {
        return sn_;
    }

    uint8_t Packet::Fields::type() const
    {
        return type_;
    }

    uint8_t Packet::Fields::size() const
    {
        return size_;
    }

    const Payload::Fields::Ptr& Packet::Fields::data() const
    {
        return data_;
    }

    uint32_t Packet::Fields::crc() const
    {
        return crc_;
    }

    const QByteArray& Packet::Fields::bytes() const
    {
        return bytes_;
    }

    Packet::Fields::Ptr Packet::fromRawData(const QByteArray& data)
    {
        auto ptr = std::make_shared<Fields>();

        ptr->sn_ = Helper::Data::valueFromBytes<uint16_t>(data);
        ptr->type_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x02);
        ptr->size_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x03); /// \todo
        ptr->crc_ = Helper::Data::valueFromBytes<uint32_t>(data , data.size() - 0x04);

        const auto payload = data.mid(0x04, static_cast<int>(ptr->size_ - sizeof(uint32_t)));

        // if (const auto crc = Packet::crc32(payload); crc != ptr->crc_) return nullptr;

        ptr->data_ = Payload::fromRawData(payload);
        ptr->bytes_ = data;

        return ptr;
    }

    /*static*/ QByteArray Packet::generateRequest(const uint16_t sn, const QByteArray& data)
    {
        auto bytes = QByteArray::fromRawData(reinterpret_cast<const char*>(&sn), sizeof(uint16_t));

        const auto crc32 = Helper::Data::crc32(data);
        const auto checksum = QByteArray::fromRawData(reinterpret_cast<const char*>(&crc32), sizeof(uint32_t));
        bytes.append(Payload::pack(static_cast<uint8_t>(Type::Request), data + checksum));

        qDebug() << Q_FUNC_INFO << bytes.toHex();

        return bytes;
    }

}
