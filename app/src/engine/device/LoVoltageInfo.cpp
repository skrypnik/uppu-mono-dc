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
        regulatorVoltage_ = *reinterpret_cast<float*>(data.mid(0x02, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x02);
        dacVoltage_ = *reinterpret_cast<float*>(data.mid(0x06, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x06);
        regulatorVoltageMin_ = *reinterpret_cast<float*>(data.mid(0x0A, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x0A);
        regulatorVoltageMax_ = *reinterpret_cast<float*>(data.mid(0x0E, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x0E);
        dacVoltageMin_ = *reinterpret_cast<float*>(data.mid(0x12, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x12);
        dacVoltageMax_ = *reinterpret_cast<float*>(data.mid(0x16, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x16);
        attenuator_ = Network::Packet::valueFromBytes<uint8_t>(data, 0x1A);
        accuracy_ = *reinterpret_cast<float*>(data.mid(0x1E, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x1E);
        regulatorRatio_ = *reinterpret_cast<float*>(data.mid(0x22, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x22);
        calibrationFactor_ = *reinterpret_cast<float*>(data.mid(0x26, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x26);
        calibrationOffset_ = *reinterpret_cast<float*>(data.mid(0x2A, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x2A);

        emit this->changed();
    }

    QVariant LoVoltageInfo::regulatorMode() const
    {
        return regulatorMode_;
    }

    QVariant LoVoltageInfo::regulatorVoltage() const
    {
        return QString::number(regulatorVoltage_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::regulatorVoltageMin() const
    {
        return QString::number(regulatorVoltageMin_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::regulatorVoltageMax() const
    {
        return QString::number(regulatorVoltageMax_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::dacVoltage() const
    {
        return QString::number(dacVoltage_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::dacVoltageMin() const
    {
        return QString::number(dacVoltageMin_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::dacVoltageMax() const
    {
        return QString::number(dacVoltageMax_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::calibrationFactor() const
    {
        return QString::number(calibrationFactor_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::calibrationOffset() const
    {
        return QString::number(calibrationOffset_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::amplifierRatio() const
    {
        return QString::number(amplifierRatio_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::regulatorRatio() const
    {
        return QString::number(regulatorRatio_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QVariant LoVoltageInfo::attenuator() const
    {
        return attenuator_;
    }

    QVariant LoVoltageInfo::accuracy() const
    {
        return QString::number(accuracy_, 'f', 6).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

}
