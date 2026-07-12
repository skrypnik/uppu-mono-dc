#include "ApplicationEngine.h"

#include <QQmlContext>

#include <model/Module.h>
#include <model/DeviceModel.h>

#include <config/Module.h>
#include <config/Common.h>

#include <network/Module.h>

#include "Dispatcher.h"
#include "device/Device.h"

namespace Enercom
{
    ApplicationEngine::ApplicationEngine(QObject* parent)
        : QQmlApplicationEngine(parent)
        , device_(new Device(this))
        , dispatcher_(new Dispatcher(this))
        , modelModule_(new Model::Module(this))
        , configModule_(new Config::Module(this))
        , networkModule_(new Network::Module(this))
    {
        QObject::connect(networkModule_, &Network::Module::incomingPacket, modelModule_->deviceModel(), &Model::DeviceModel::onIncomingDeviceInfo);

        QObject::connect(networkModule_, &Network::Module::incomingBroadcastPacket, dispatcher_, &Dispatcher::onIncomingPacket);

        QObject::connect(dispatcher_, &Dispatcher::deviceInfoReceived, modelModule_->deviceModel(), &Model::DeviceModel::onDeviceInfoChanged);

        QObject::connect(modelModule_->deviceModel(), &Model::DeviceModel::deviceInfoChanged, device_, &Device::onDeviceInfoChanged);
    }

    void ApplicationEngine::initializeEngine()
    {
        Config::Common::get().load();

        networkModule_->initialize();

        this->rootContext()->setContextProperty("engine", this);

        this->addImportPath("qrc:/");

        this->load("qrc:/AppUI/qml/main.qml");
    }

    QVariant ApplicationEngine::device() const
    {
        return QVariant::fromValue( device_ );
    }

    QVariant ApplicationEngine::modelModule() const
    {
        return QVariant::fromValue( modelModule_ );
    }

    QVariant ApplicationEngine::configModule() const
    {
        return QVariant::fromValue( configModule_ );
    }

    QVariant ApplicationEngine::networkModule() const
    {
        return QVariant::fromValue( networkModule_ );
    }

}
