#include "Module.h"

#include "DeviceModel.h"
#include "MeterModel.h"

namespace Enercom::Model
{
    Module::Module(QObject* parent)
        : QObject(parent)
        , deviceModel_(new DeviceModel(this))
        , meterModel_(new MeterModel(this))
    {

    }

    const DeviceModel* Module::deviceModel() const
    {
        return deviceModel_;
    }

    const MeterModel* Module::meterModel() const
    {
        return meterModel_;
    }

    QVariant Module::meters() const
    {
        return QVariant::fromValue(meterModel_);
    }

    QVariant Module::devices() const
    {
        return QVariant::fromValue(deviceModel_);
    }

}
