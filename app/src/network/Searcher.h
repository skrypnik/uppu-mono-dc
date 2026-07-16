#pragma once

#include <QUdpSocket>
#include <QTimer>

#include <network/Packet.h>

namespace Enercom::Network
{
    /**
     * Network device searcher
     */
    class Searcher final : public QTimer
    {
        Q_OBJECT

    public:
        /**
         * Constructs device searcher object
         * @param parent parent QObject to call safe deleter
         */
        explicit Searcher(QObject* parent = nullptr);

        /**
         * Initializes searcher with given port
         */
        void initialize();

        /**
         * Sends broadcast request
         */
        void sendBroadcastRequest() const;

    signals:
        /**
         * Emits, when module receives response on broadcast request
         * @param packet response packet data
         */
        void incomingBroadcastPacket(const Enercom::Network::Packet::Fields::Ptr& packet);

    private slots:
        /**
         * Sends broadcast request
         */
        void onSendBroadcastRequest() const;

        /**
         * Incoming data handler
         */
        void onReceiveBroadcastRequest();

    private:
        /**
         * UDP socket for broadcast messaging
         */
        QUdpSocket* socket_;
    };

}
