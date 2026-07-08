#pragma once

#include <QByteArray>

#include <vector>

namespace Enercom
{
    class Helper
    {
        static const std::vector<uint32_t> polynomial;

    public:
        /**
        * Returns CRC32‑IEEE802.3 checksum
        * @param data given data
        * @return CRC32‑IEEE802.3 checksum
        */
        static uint32_t crc32(const QByteArray& data);
    };

}