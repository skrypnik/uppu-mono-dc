#include "CalibratorReadings.h"

#include <helper/Data.h>
#include <helper/View.h>

#include <QDebug>

namespace Enercom
{
    CalibratorReadings::CalibratorReadings(QObject* parent)
        : QObject(parent)
    {

    }

    void CalibratorReadings::fromRawData(const QByteArray& data)
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

    QVariant CalibratorReadings::voltage() const
    {
        return Helper::View::normalizedFloat(voltage_);
    }

    QVariant CalibratorReadings::current() const
    {
        return Helper::View::normalizedFloat(current_);
    }

    QVariant CalibratorReadings::power() const
    {
        return Helper::View::normalizedFloat(power_);
    }

    QVariant CalibratorReadings::energy() const
    {
        return Helper::View::normalizedFloat(energy_);
    }

    QVariant CalibratorReadings::pulsePeriod() const
    {
        return Helper::View::normalizedFloat(pulsePeriod_);
    }

    QVariant CalibratorReadings::pulseCount() const
    {
        return pulseCount_;
    }

}
