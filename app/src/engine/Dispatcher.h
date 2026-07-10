#pragma once

#include <QObject>

#include <network/Packet.h>

namespace Enercom
{
    /**
     * Packet dispatcher
     */
    class Dispatcher final : public QObject
    {
        Q_OBJECT

    public:
        /**
         * Constructs dispatcher object
         * @param parent parent QObject to call safe deleter
         */
        explicit Dispatcher(QObject *parent = nullptr);

    signals:
        /**
         * Emits, when device info received
         * @param data packet data
         */
        void deviceInfoReceived(const Enercom::Network::Packet::Fields::Ptr& data);

    public slots:
        /**
        * Incoming data handler
        * @param data response raw data
        */
        void onIncomingData(const Enercom::Network::Packet::Fields::Ptr& data);
    };

}
