#include "CalibratorInfo.h"

#include <helper/Data.h>
#include <helper/View.h>

#include <QDebug>

namespace Enercom
{
    CalibratorInfo::CalibratorInfo(QObject* parent)
    {
    }

    void CalibratorInfo::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        constant_ = Helper::Data::valueFromBytes<uint32_t>(data, 0x02);
        current_ = Helper::Data::valueFromBytes<float>(data, 0x06);
        voltage_ = Helper::Data::valueFromBytes<float>(data, 0x0A);

        emit this->changed();
    }

    QVariant CalibratorInfo::constant() const
    {
        return QString::number(constant_);
    }

    QVariant CalibratorInfo::current() const
    {
        return Helper::View::normalizedFloat(current_);
    }

    QVariant CalibratorInfo::voltage() const
    {
        return Helper::View::normalizedFloat(voltage_);
    }
}
