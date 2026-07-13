#include "HiVoltageInfo.h"

#include <network/Packet.h>

#include <QDebug>

namespace Enercom
{
    HiVoltageInfo::HiVoltageInfo(QObject* parent)
        : QObject(parent)
    {

    }

    void HiVoltageInfo::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        qDebug() << "HiVoltageInfo::fromRawData";

        regulatorMode_ = Network::Packet::valueFromBytes<uint8_t>(data, 0x01);
        regulatorVoltage_ = *reinterpret_cast<float*>(data.mid(0x02, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x02);
        dacVoltage_ = *reinterpret_cast<float*>(data.mid(0x06, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x06);
        regulatorVoltageMin_ = *reinterpret_cast<float*>(data.mid(0x0A, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x0A);
        regulatorVoltageMax_ = *reinterpret_cast<float*>(data.mid(0x0E, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x0E);
        dacVoltageMin_ = *reinterpret_cast<float*>(data.mid(0x12, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x12);
        dacVoltageMax_ = *reinterpret_cast<float*>(data.mid(0x16, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x16);
        dividerRatio_ = *reinterpret_cast<float*>(data.mid(0x1A, sizeof(float)).data());
        accuracy_ = *reinterpret_cast<float*>(data.mid(0x1E, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x1E);
        regulatorRatio_ = Network::Packet::valueFromBytes<uint32_t>(data, 0x22);
        calibrationFactor_ = *reinterpret_cast<float*>(data.mid(0x26, sizeof(float)).data());  // Network::Packet::valueFromBytes<float>(data, 0x26);
        calibrationOffset_ = *reinterpret_cast<float*>(data.mid(0x2A, sizeof(float)).data()); // Network::Packet::valueFromBytes<uint32_t>(data, 0x2A);

        emit this->changed();
    }

    QVariant HiVoltageInfo::regulatorMode() const
    {
        return regulatorMode_;
    }

    QVariant HiVoltageInfo::regulatorVoltage() const
    {
        return QString::number(regulatorVoltage_, 'f', 6);
    }

    QVariant HiVoltageInfo::regulatorVoltageMin() const
    {
        return QString::number(regulatorVoltageMin_, 'f', 6);
    }

    QVariant HiVoltageInfo::regulatorVoltageMax() const
    {
        return QString::number(regulatorVoltageMax_, 'f', 6);
    }

    QVariant HiVoltageInfo::dacVoltage() const
    {
        return QString::number(dacVoltage_, 'f', 6);
    }

    QVariant HiVoltageInfo::dacVoltageMin() const
    {
        return QString::number(dacVoltageMin_, 'f', 6);
    }

    QVariant HiVoltageInfo::dacVoltageMax() const
    {
        return QString::number(dacVoltageMax_, 'f', 6);
    }

    QVariant HiVoltageInfo::calibrationFactor() const
    {
        return QString::number(calibrationFactor_, 'f', 6);
    }

    QVariant HiVoltageInfo::calibrationOffset() const
    {
        return QString::number(calibrationOffset_, 'f', 6);
    }

    QVariant HiVoltageInfo::dividerRatio() const
    {
        return QString::number(dividerRatio_, 'f', 6);
    }

    QVariant HiVoltageInfo::regulatorRatio() const
    {
        return regulatorRatio_;
    }

    QVariant HiVoltageInfo::accuracy() const
    {
        return QString::number(accuracy_, 'f', 6);
    }

}
