#pragma once

#include <QObject>

#include <memory>

#include <network/Packet.h>

#include "DataView.h"

namespace Enercom::Model
{
    /**
     * Protocol model item
     */
    class PacketItem final : public QObject
    {
        Q_OBJECT

        /**
         * Packet serial number 2-digit hex view property
         */
        Q_PROPERTY( QStringList sn READ sn CONSTANT )

        /**
         * Packet checksum 2-digit hex view property
         */
        Q_PROPERTY( QStringList crc READ crc CONSTANT )

        /**
         * Packet TLV wrapper property
         */
        Q_PROPERTY( QVariant packet READ packet CONSTANT )

        /**
         * Payload TLV wrapper property
         */
        Q_PROPERTY( QVariant payload READ payload CONSTANT )

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<PacketItem>;

    public:
        /**
         * Constructs model item object
         * @param data packet data pointer
         * @param parent parent QObject to call safe deleter
         */
        explicit PacketItem(Network::Packet::Fields::Ptr data, QObject* parent = nullptr);

    private:
        /**
         * Packet serial number 2-digit hex view getter
         */
        [[nodiscard]] const QStringList& sn() const;

        /**
         * Packet checksum 2-digit hex view getter
         */
        [[nodiscard]] const QStringList& crc() const;

        /**
         * Packet TLV wrapper getter
         */
        [[nodiscard]] QVariant packet() const;

        /**
         * Payload TLV wrapper getter
         */
        [[nodiscard]] QVariant payload() const;

    private:
        /**
         * Packet serial number 2-digit hex view
         */
        QStringList sn_;

        /**
         * Packet checksum 2-digit hex view
         */
        QStringList crc_;

        /**
         * Packet TLV wrapper
         */
        DataView::Ptr packet_;

        /**
         * Payload TLV wrapper
         */
        DataView::Ptr payload_;

        /**
         * Packet data pointer
         */
        Network::Packet::Fields::Ptr data_;
    };

}