#pragma once

#include "Payload.h"

#include <vector>

namespace Enercom::Network
{
    /**
    * class Packet
    */
    class Packet
    {
        /**
        * Construction is deprecated
        */
        Packet() = default;

    public:
        /**
        * Packet type
        */
        enum class Type : uint8_t
        {
            Request  = 0x80,
            Response = 0x81
        };

    public:
        /**
         * Decomposed packet data
         */
        class Fields
        {
            /**
             * For easy usage in Packet class
             */
            friend class Packet;

        public:
            /**
             * Alias for shared_ptr
             */
            using Ptr = std::shared_ptr<Fields>;

        public:
            /**
             * Default constructor
             */
            Fields();

            /**
             * Device serial number getter
             */
            [[nodiscard]] uint16_t sn() const;

            /**
             * Packet type according to Packet::Type enum getter
             */
            [[nodiscard]] uint8_t type() const;

            /**
             * Packet data size including checksum getter
             */
            [[nodiscard]] uint8_t size() const;

            /**
             * Payload data getter
             */
            [[nodiscard]] const Payload::Fields::Ptr& data() const;

            /**
             * Payload checksum getter
             */
            [[nodiscard]] uint32_t crc() const;

            /**
             * Packet raw data getter
             */
            [[nodiscard]] const QByteArray& bytes() const;

        private:
            /**
             * Device serial number
             */
            uint16_t sn_{};

            /**
             * Packet type according to Packet::Type enum
             */
            uint8_t type_ {};

            /**
             * Payload size including checksum
             */
            uint8_t size_ {}; /// \todo

            /**
             * Payload data
             */
            Payload::Fields::Ptr data_;

            /**
             * Payload checksum
             */
            uint32_t crc_ {};

            /**
             * Packet raw data
             */
            QByteArray bytes_;
        };

    public:
        /**
         * Decompose packet raw data
         * @param data packet raw data
         * @return pointer to decomposed data
         */
        static Fields::Ptr fromRawData(const QByteArray& data);

        /**
        * Generates request packet
        * @param sn device serial number
        * @param data TLV formated request raw data
        * @return request packet raw data
        */
        static QByteArray generateRequest(uint16_t sn, const QByteArray& data);

    public:
        /**
        * Construction is deprecated
        */
        Packet(const Packet&) = delete;
        Packet(Packet&&) = delete;
        Packet& operator=(const Packet&) = delete;
        Packet& operator=(Packet&&) = delete;
    };

}
