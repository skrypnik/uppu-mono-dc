#include "Module.h"

#include "DeviceModel.h"

namespace Enercom::Model
{
    Module::Module(QObject* parent)
        : QObject(parent)
        , deviceModel_(new DeviceModel(this))
    {

    }

    const DeviceModel* Module::deviceModel() const
    {
        return deviceModel_;
    }

    QVariant Module::devices() const
    {
        return QVariant::fromValue(deviceModel_);
    }

}
