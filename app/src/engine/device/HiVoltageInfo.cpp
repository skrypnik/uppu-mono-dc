#include "HiVoltageInfo.h"

#include <network/Packet.h>

namespace Enercom
{
    HiVoltageInfo::HiVoltageInfo(QObject* parent)
        : QObject(parent)
    {

    }

    void HiVoltageInfo::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        regulatorMode_ = Network::Packet::valueFromBytes<uint8_t>(data, 0x01);
        regulatorVoltage_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x02);
        dacVoltage_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x06);
        regulatorVoltageMin_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x0A);
        regulatorVoltageMax_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x0E);
        dacVoltageMin_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x12);
        dacVoltageMax_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x16);
        accuracy_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x1E);
        regulatorRatio_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x22);
        calibrationFactor_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x26);
        calibrationOffset_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x2A);

        emit this->changed();
    }

    QVariant HiVoltageInfo::regulatorMode() const
    {
        return regulatorMode_;
    }

    QVariant HiVoltageInfo::regulatorVoltage() const
    {
        return regulatorVoltage_;
    }

    QVariant HiVoltageInfo::regulatorVoltageMin() const
    {
        return regulatorVoltageMin_;
    }

    QVariant HiVoltageInfo::regulatorVoltageMax() const
    {
        return regulatorVoltageMax_;
    }

    QVariant HiVoltageInfo::dacVoltage() const
    {
        return dacVoltage_;
    }

    QVariant HiVoltageInfo::dacVoltageMin() const
    {
        return dacVoltageMin_;
    }

    QVariant HiVoltageInfo::dacVoltageMax() const
    {
        return dacVoltageMax_;
    }

    QVariant HiVoltageInfo::calibrationFactor() const
    {
        return calibrationFactor_;
    }

    QVariant HiVoltageInfo::calibrationOffset() const
    {
        return calibrationOffset_;
    }

    QVariant HiVoltageInfo::dividerRatio() const
    {
        return dividerRatio_;
    }

    QVariant HiVoltageInfo::regulatorRatio() const
    {
        return regulatorRatio_;
    }

    QVariant HiVoltageInfo::accuracy() const
    {
        return accuracy_;
    }

}
