#include "MetersInfo.h"

#include <helper/Data.h>
#include <helper/View.h>

#include <QDebug>

namespace Enercom
{
    MetersInfo::MetersInfo(QObject* parent)
        : QObject(parent)
        , availableSpeedValues_({ "2400", "4800", "9600", "19200", "28800", "38400", "57600", "76800", "115200" })
    {

    }

    void MetersInfo::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        const auto count = Helper::Data::valueFromBytes<uint8_t>(data, 0x01);

        if (count_ != count) emit clearMeterModel();

        count_ = count;
        baudRate_ = Helper::Data::valueFromBytes<uint32_t>(data, 0x02);
        inputKind_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x06);
        inputVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x07);
        outputVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x0B);

        emit this->requestEachMeterInfo(count);

        emit this->changed();
    }

    QVariant MetersInfo::count() const
    {
        return QString::number(count_);
    }

    QVariant MetersInfo::baudRate() const
    {
        return QString::number(baudRate_);
    }

    QVariant MetersInfo::inputKind() const
    {
        return inputKind_;
    }

    QVariant MetersInfo::inputVoltage() const
    {
        return Helper::View::normalizedFloat(inputVoltage_);
    }

    QVariant MetersInfo::outputVoltage() const
    {
        return Helper::View::normalizedFloat(outputVoltage_);
    }

    QVariant MetersInfo::baudRateIndex() const
    {
        return availableSpeedValues_.indexOf(QString::number(baudRate_));
    }

    QVariant MetersInfo::availableSpeedValues() const
    {
        return availableSpeedValues_;
    }
}
