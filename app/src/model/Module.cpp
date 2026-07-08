#include "Module.h"

#include "PacketModel.h"

namespace Enercom::Model
{
    Module::Module(QObject* parent)
        : QObject(parent)
        , packetModel_(new PacketModel(this))
    {

    }

    const PacketModel* Module::packetModel() const
    {
        return packetModel_;
    }

    QVariant Module::packet() const
    {
        return QVariant::fromValue(packetModel_);
    }

}
