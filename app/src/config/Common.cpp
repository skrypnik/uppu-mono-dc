#include "Common.h"

#include <QStandardPaths>
#include <QJsonDocument>
#include <QDir>

namespace Enercom::Config
{
    /*static*/ const QString Common::ConfigLocation = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    /*static*/ const QString Common::ConfigFileName = "config.json";
    /*static*/ const QString Common::ConfigDir = "uppu-mono-dc";

    void Common::createDefault()
    {
        QJsonObject application;
        application["title"] = "УППУ Моно DC";

        QJsonObject network;
        network["host"] = "192.168.1.1";
        network["port"] = 63500;

        QJsonObject service;
        service["port"] = 57555;

        root_["application"] = application;
        root_["network"] = network;
        root_["service"] = service;
    }

    /*static*/ Common& Common::get()
    {
        static Common instance;
        return instance;
    }

    bool Common::load()
    {
        const auto configPath = QString("%1/%2").arg(ConfigLocation, ConfigDir);

        if (const QDir dir(configPath); !dir.exists())
        {
            Q_UNUSED( dir.mkdir(configPath) );

            this->createDefault();

            this->save();
        }

        const auto configFile = QString("%1/%2").arg(configPath, ConfigFileName);

        if (QFile file{configFile}; file.open(QFile::ReadOnly | QFile::Text))
        {
            QJsonParseError error = {QJsonParseError::NoError};
            const auto doc = QJsonDocument::fromJson(file.readAll(), &error);

            if (error.error == QJsonParseError::NoError)
            {
                root_ = doc.object();

                return true;
            }
        }

        return false;
    }

    bool Common::save()
    {
        const auto configPath = QString("%1/%2").arg(ConfigLocation, ConfigDir);

        if (const QDir dir(configPath); !dir.exists())
        {
            Q_UNUSED(dir.mkdir(configPath));

            this->createDefault();
        }

        const auto configFile = QString("%1/%2").arg(configPath, ConfigFileName);

        if (QFile file(configFile); file.open(QFile::WriteOnly | QFile::Text))
        {
            const QJsonDocument doc(root_);
            file.write(doc.toJson());

            return true;
        }

        return false;
    }

    const QJsonObject& Common::root() const
    {
        return root_;
    }

    void Common::setConfigObject(const QString& key, const QJsonObject& obj)
    {
        ///! \todo check key

        root_[key] = obj;

        this->save();
    }

}
