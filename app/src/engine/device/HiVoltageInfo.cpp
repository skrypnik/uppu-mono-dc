#include "HiVoltageInfo.h"

#include <network/Packet.h>

#include <helper/Data.h>
#include <helper/View.h>

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

        regulatorMode_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x01);
        regulatorVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x02);
        dacVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x06);
        regulatorVoltageMin_ = Helper::Data::valueFromBytes<float>(data, 0x0A);
        regulatorVoltageMax_ = Helper::Data::valueFromBytes<float>(data, 0x0E);
        dacVoltageMin_ = Helper::Data::valueFromBytes<float>(data, 0x12);
        dacVoltageMax_ = Helper::Data::valueFromBytes<float>(data, 0x16);
        dividerRatio_ =  Helper::Data::valueFromBytes<float>(data, 0x1A);
        accuracy_ = Helper::Data::valueFromBytes<float>(data, 0x1E);
        regulatorRatio_ = Helper::Data::valueFromBytes<uint32_t>(data, 0x22);
        calibrationFactor_ = Helper::Data::valueFromBytes<float>(data, 0x26);
        calibrationOffset_ = Helper::Data::valueFromBytes<float>(data, 0x2A);

        emit this->changed();
    }

    QVariant HiVoltageInfo::regulatorMode() const
    {
        return regulatorMode_;
    }

    QVariant HiVoltageInfo::regulatorVoltage() const
    {
        return Helper::View::normalizedFloat(regulatorVoltage_);
    }

    QVariant HiVoltageInfo::regulatorVoltageMin() const
    {
        return Helper::View::normalizedFloat(regulatorVoltageMin_);
    }

    QVariant HiVoltageInfo::regulatorVoltageMax() const
    {
        return Helper::View::normalizedFloat(regulatorVoltageMax_);
    }

    QVariant HiVoltageInfo::dacVoltage() const
    {
        return Helper::View::normalizedFloat(dacVoltage_);
    }

    QVariant HiVoltageInfo::dacVoltageMin() const
    {
        return Helper::View::normalizedFloat(dacVoltageMin_);
    }

    QVariant HiVoltageInfo::dacVoltageMax() const
    {
        return Helper::View::normalizedFloat(dacVoltageMax_);
    }

    QVariant HiVoltageInfo::calibrationFactor() const
    {
        return Helper::View::normalizedFloat(calibrationFactor_);
    }

    QVariant HiVoltageInfo::calibrationOffset() const
    {
        return Helper::View::normalizedFloat(calibrationOffset_);
    }

    QVariant HiVoltageInfo::dividerRatio() const
    {
        return Helper::View::normalizedFloat(dividerRatio_);
    }

    QVariant HiVoltageInfo::regulatorRatio() const
    {
        return regulatorRatio_;
    }

    QVariant HiVoltageInfo::accuracy() const
    {
        return Helper::View::normalizedFloat(accuracy_);
    }

}
