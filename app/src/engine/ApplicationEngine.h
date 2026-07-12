#pragma once

#include <QQmlApplicationEngine>

class QTcpSocket;
class QTimer;

namespace Enercom
{
    /**
     * Current device
     */
    class Device;

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
         * Current device
        */
        Q_PROPERTY( QVariant device READ device CONSTANT )

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
        * Current device
        */
        [[nodiscard]] QVariant device() const;

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
        * Current device
        */
        Device* device_;

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
