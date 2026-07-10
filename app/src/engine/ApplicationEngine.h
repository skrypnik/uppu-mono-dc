#pragma once

#include <QQmlApplicationEngine>

class QTcpSocket;
class QTimer;

namespace Enercom
{
    /**
     * Packet dispatcher
     */
    class Dispatcher;

    /**
    * Model module
    */
    namespace Model { class Module; }

    /**
    * Config module
    */
    namespace Config { class Module; }

    /**
    * Network module
    */
    namespace Network { class Module; }

    /**
     * Application engine
     */
    class ApplicationEngine final : public QQmlApplicationEngine
    {
        Q_OBJECT

        /**
         * Model module
         */
        Q_PROPERTY( QVariant model READ modelModule CONSTANT )

        /**
         * Config module
         */
        Q_PROPERTY( QVariant config READ configModule CONSTANT )

        /**
         * Network module
         */
        Q_PROPERTY( QVariant network READ networkModule CONSTANT )

    public:
        /**
         * Constructs application engine object
         * @param parent parent QObject to call safe deleter
         */
        explicit ApplicationEngine(QObject* parent = nullptr);

        /**
         * Initializes application engine
         */
        void initializeEngine();

    private:
        /**
        * Model module metaobject property getter
        * @return module module pointer
        */
        [[nodiscard]] QVariant modelModule() const;

        /**
        * Config module metaobject property getter
        * @return config module pointer
        */
        [[nodiscard]] QVariant configModule() const;

        /**
         * Network module metaobject property getter
         * @return network module pointer
         */
        [[nodiscard]] QVariant networkModule() const;

    private:
        /**
        * Packet dispatcher
        */
        Dispatcher* dispatcher_;

        /**
         * Model module
         */
        Model::Module* modelModule_;

        /**
         * Config module
         */
        Config::Module* configModule_;

        /**
         * Network module
         */
        Network::Module* networkModule_;
    };

}
