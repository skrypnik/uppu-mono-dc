#include "ApplicationEngine.h"

#include <QQmlContext>

#include <model/Module.h>

#include <config/Module.h>
#include <config/Common.h>

#include <network/Module.h>
#include <network/Searcher.h>

#include "model/PacketModel.h"

namespace Enercom
{
    ApplicationEngine::ApplicationEngine(QObject* parent)
        : QQmlApplicationEngine(parent)
        , modelModule_(new Model::Module(this))
        , configModule_(new Config::Module(this))
        , networkModule_(new Network::Module(this))
        , networkSearcher_(new Network::Searcher(this))
    {
        QObject::connect(networkModule_, &Network::Module::outgoingPacket, modelModule_->packetModel(), &Model::PacketModel::onOutgoingData);
        QObject::connect(networkModule_, &Network::Module::incomingPacket, modelModule_->packetModel(), &Model::PacketModel::onIncomingData);
    }

    void ApplicationEngine::initializeEngine()
    {
        /// Load config data
        Config::Common::get().load();

        /// Set root context property name
        this->rootContext()->setContextProperty("engine", this);

        /// Add resource import path
        this->addImportPath("qrc:/");

        /// Load UI resources
        this->load("qrc:/qml/main.qml");
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
