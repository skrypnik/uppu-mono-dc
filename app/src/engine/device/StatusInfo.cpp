#include "StatusInfo.h"

#include <helper/Data.h>
#include <helper/View.h>

#include <QDebug>

namespace Enercom
{
    StatusInfo::StatusInfo(QObject* parent)
        : QObject(parent)
    {

    }

    void StatusInfo::fromRawData(const QByteArray& data)
    {
        /// \todo check response code

        hiVoltageReady_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x01);
        hiVoltageGeneration_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x02);
        hiVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x03);
        hiVoltageDAC_ = Helper::Data::valueFromBytes<float>(data, 0x07);
        hiVoltageADC_ = Helper::Data::valueFromBytes<float>(data, 0x0B);

        loVoltageReady_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x0F);
        loVoltageGeneration_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x10);
        loVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x11);
        loVoltageDAC_ = Helper::Data::valueFromBytes<float>(data, 0x15);
        loVoltageADC_ = Helper::Data::valueFromBytes<float>(data, 0x19);

        metersPowerStatus_ = Helper::Data::valueFromBytes<uint8_t>(data, 0x1D);
        outputVoltage_ = Helper::Data::valueFromBytes<float>(data, 0x1E);

        emit this->changed();
    }

    QVariant StatusInfo::hiVoltageReady() const
    {
        return hiVoltageReady_;
    }

    QVariant StatusInfo::hiVoltageGeneration() const
    {
        return hiVoltageGeneration_;
    }

    QVariant StatusInfo::hiVoltage() const
    {
        return Helper::View::normalizedFloat(hiVoltage_);
    }

    QVariant StatusInfo::hiVoltageDAC() const
    {
        return Helper::View::normalizedFloat(hiVoltageDAC_);
    }

    QVariant StatusInfo::hiVoltageADC() const
    {
        return Helper::View::normalizedFloat(hiVoltageADC_);
    }

    QVariant StatusInfo::loVoltageReady() const
    {
        return loVoltageReady_;
    }

    QVariant StatusInfo::loVoltageGeneration() const
    {
        return loVoltageGeneration_;
    }

    QVariant StatusInfo::loVoltage() const
    {
        return Helper::View::normalizedFloat(loVoltage_);
    }

    QVariant StatusInfo::loVoltageDAC() const
    {
        return Helper::View::normalizedFloat(loVoltageDAC_);
    }

    QVariant StatusInfo::loVoltageADC() const
    {
        return Helper::View::normalizedFloat(loVoltageADC_);
    }

    QVariant StatusInfo::metersPowerStatus() const
    {
        return metersPowerStatus_;
    }

    QVariant StatusInfo::outputVoltage() const
    {
        return Helper::View::normalizedFloat(outputVoltage_);
    }
}
