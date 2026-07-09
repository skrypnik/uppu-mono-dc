#include "ApplicationEngine.h"

#include <QQmlContext>

#include <model/Module.h>

#include <config/Module.h>
#include <config/Common.h>

#include <network/Module.h>
#include <network/Searcher.h>

#include "model/DeviceModel.h"

namespace Enercom
{
    ApplicationEngine::ApplicationEngine(QObject* parent)
        : QQmlApplicationEngine(parent)
        , modelModule_(new Model::Module(this))
        , configModule_(new Config::Module(this))
        , networkModule_(new Network::Module(this))
        , networkSearcher_(new Network::Searcher(this))
    {
        QObject::connect(networkModule_, &Network::Module::incomingPacket, modelModule_->deviceModel(), &Model::DeviceModel::onIncomingData);
    }

    void ApplicationEngine::initializeEngine()
    {
        /// \todo get port from config file
        networkSearcher_->startSearch( 57555 );

        /// Load config data
        Config::Common::get().load();

        /// Set root context property name
        this->rootContext()->setContextProperty("engine", this);

        /// Add resource import path
        this->addImportPath("qrc:/");

        /// Load AppUI resources
        this->load("qrc:/AppUI/qml/main.qml");
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
