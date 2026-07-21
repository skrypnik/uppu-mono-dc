#include "LoVoltageInfo.h"

#include <network/Packet.h>

#include <helper/Data.h>
#include <helper/View.h>

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

        regulatorMode_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x01);
        regulatorVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x02);
        dacVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x06);
        regulatorVoltageMin_ = Helper::Data::valueFromBytes<float>(data, 0x0A);
        regulatorVoltageMax_ = Helper::Data::valueFromBytes<float>(data, 0x0E);
        dacVoltageMin_ = Helper::Data::valueFromBytes<float>(data, 0x12);
        dacVoltageMax_ = Helper::Data::valueFromBytes<float>(data, 0x16);
        attenuator_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x1A);
        amplifierRatio_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x1B);
        accuracy_ = Helper::Data::valueFromBytes<float>(data, 0x1E);
        regulatorRatio_ = Helper::Data::valueFromBytes<float>(data, 0x22);
        calibrationFactor_ = Helper::Data::valueFromBytes<float>(data, 0x26);
        calibrationOffset_ = Helper::Data::valueFromBytes<float>(data, 0x2A);

        emit this->changed();
    }

    QVariant LoVoltageInfo::regulatorMode() const
    {
        return regulatorMode_;
    }

    QVariant LoVoltageInfo::regulatorVoltage() const
    {
        return Helper::View::normalizedFloat(regulatorVoltage_);
    }

    QVariant LoVoltageInfo::regulatorVoltageMin() const
    {
        return Helper::View::normalizedFloat(regulatorVoltageMin_);
    }

    QVariant LoVoltageInfo::regulatorVoltageMax() const
    {
        return Helper::View::normalizedFloat(regulatorVoltageMax_);
    }

    QVariant LoVoltageInfo::dacVoltage() const
    {
        return Helper::View::normalizedFloat(dacVoltage_);
    }

    QVariant LoVoltageInfo::dacVoltageMin() const
    {
        return Helper::View::normalizedFloat(dacVoltageMin_);
    }

    QVariant LoVoltageInfo::dacVoltageMax() const
    {
        return Helper::View::normalizedFloat(dacVoltageMax_);
    }

    QVariant LoVoltageInfo::calibrationFactor() const
    {
        return Helper::View::normalizedFloat(calibrationFactor_);
    }

    QVariant LoVoltageInfo::calibrationOffset() const
    {
        return Helper::View::normalizedFloat(calibrationOffset_);
    }

    QVariant LoVoltageInfo::amplifierRatio() const
    {
        return amplifierRatio_;
    }

    QVariant LoVoltageInfo::regulatorRatio() const
    {
        return Helper::View::normalizedFloat(regulatorRatio_);
    }

    QVariant LoVoltageInfo::attenuator() const
    {
        return attenuator_;
    }

    QVariant LoVoltageInfo::accuracy() const
    {
        return Helper::View::normalizedFloat(accuracy_);
    }

}
