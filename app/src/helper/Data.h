#pragma once

#include <QByteArray>

#include <vector>

namespace Enercom::Helper
{
    /**
     * Common data parse and serialize helper
     */
    class Data
    {
        /**
         * Polynomial table to fast checksum calculation
         */
        static const std::vector<uint32_t> polynomial;

    public:
        /**
        * Returns CRC32‑IEEE802.3 checksum
        * @param data given data
        * @return CRC32‑IEEE802.3 checksum
        */
        static uint32_t crc32(const QByteArray& data);

    public:
        /**
         * Template helper function for give value from raw data
         * @tparam T data type
         * @param data byte array
         * @param offset offset from start of array
         * @return bytes from data converted to T type
         */
        template<class T> static T valueFromBytes(const QByteArray& data, const int offset = 0x00) {

            return *reinterpret_cast<T*>(data.mid(offset, sizeof(T)).data());
        }
    };

}
