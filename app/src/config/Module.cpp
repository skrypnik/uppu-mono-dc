#include "Module.h"

#include "Common.h"

namespace Enercom::Config
{
    Module::Module(QObject* parent)
        : QObject(parent)
    {

    }

    QVariant Module::applicationTitle() const
    {
        return Common::get().root()["application"]["title"].toString();
    }

    QVariant Module::connectionHost() const
    {
        return Common::get().root()["network"]["host"].toString();
    }

    QVariant Module::connectionPort() const
    {
        return Common::get().root()["network"]["port"].toInt();
    }

}
