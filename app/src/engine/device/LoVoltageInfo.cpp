#include "LoVoltageInfo.h"

#include <network/Packet.h>

#include <QDebug>

namespace Enercom
{
    LoVoltageInfo::LoVoltageInfo(QObject* parent)
        : QObject(parent)
    {

    }

    void LoVoltageInfo::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        regulatorMode_ = Network::Packet::valueFromBytes<uint8_t>(data, 0x01);
        regulatorVoltage_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x02);
        dacVoltage_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x06);
        regulatorVoltageMin_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x0A);
        regulatorVoltageMax_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x0E);
        dacVoltageMin_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x12);
        dacVoltageMax_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x16);
        attenuator_ = Network::Packet::valueFromBytes<uint8_t>(data, 0x1A);
        accuracy_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x1E);
        regulatorRatio_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x22);
        calibrationFactor_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x26);
        calibrationOffset_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x2A);

        emit this->changed();
    }

    QVariant LoVoltageInfo::regulatorMode() const
    {
        return regulatorMode_;
    }

    QVariant LoVoltageInfo::regulatorVoltage() const
    {
        return regulatorVoltage_;
    }

    QVariant LoVoltageInfo::regulatorVoltageMin() const
    {
        return regulatorVoltageMin_;
    }

    QVariant LoVoltageInfo::regulatorVoltageMax() const
    {
        return regulatorVoltageMax_;
    }

    QVariant LoVoltageInfo::dacVoltage() const
    {
        return dacVoltage_;
    }

    QVariant LoVoltageInfo::dacVoltageMin() const
    {
        return dacVoltageMin_;
    }

    QVariant LoVoltageInfo::dacVoltageMax() const
    {
        return dacVoltageMax_;
    }

    QVariant LoVoltageInfo::calibrationFactor() const
    {
        return calibrationFactor_;
    }

    QVariant LoVoltageInfo::calibrationOffset() const
    {
        return calibrationOffset_;
    }

    QVariant LoVoltageInfo::amplifierRatio() const
    {
        return amplifierRatio_;
    }

    QVariant LoVoltageInfo::regulatorRatio() const
    {
        return regulatorRatio_;
    }

    QVariant LoVoltageInfo::attenuator() const
    {
        return attenuator_;
    }

    QVariant LoVoltageInfo::accuracy() const
    {
        return accuracy_;
    }

}
