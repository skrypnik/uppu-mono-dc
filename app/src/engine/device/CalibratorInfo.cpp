#include "CalibratorInfo.h"

#include <helper/Data.h>
#include <helper/View.h>

#include <QDebug>

namespace Enercom
{
    CalibratorInfo::CalibratorInfo(QObject* parent)
        : QObject(parent)
    {

    }

    void CalibratorInfo::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        voltage_ = Helper::Data::valueFromBytes<float>(data, 0x01);
        current_ = Helper::Data::valueFromBytes<float>(data, 0x05);
        power_ = Helper::Data::valueFromBytes<float>(data, 0x09);
        energy_ = Helper::Data::valueFromBytes<float>(data, 0x0D);
        pulsePeriod_ = Helper::Data::valueFromBytes<float>(data, 0x11);
        pulseCount_ = Helper::Data::valueFromBytes<uint32_t>(data, 0x15);

        emit this->changed();
    }

    QVariant CalibratorInfo::voltage() const
    {
        return Helper::View::normalizedFloat(voltage_);
    }

    QVariant CalibratorInfo::current() const
    {
        return Helper::View::normalizedFloat(current_);
    }

    QVariant CalibratorInfo::power() const
    {
        return Helper::View::normalizedFloat(power_);
    }

    QVariant CalibratorInfo::energy() const
    {
        return Helper::View::normalizedFloat(energy_);
    }

    QVariant CalibratorInfo::pulsePeriod() const
    {
        return Helper::View::normalizedFloat(pulsePeriod_);
    }

    QVariant CalibratorInfo::pulseCount() const
    {
        return pulseCount_;
    }

}
