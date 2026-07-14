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

        /**
         * Emits, when status info received
         * @param data packet data
         */
        void deviceStatusInfoReceived(const Enercom::Network::Packet::Fields::Ptr& data);

        /**
         * Emits, when device info received
         * @param data packet data
         */
        void deviceBroadcastInfoReceived(const Enercom::Network::Packet::Fields::Ptr& data);

        /**
         * Emits, when device high voltage info received
         * @param data packet data
         */
        void deviceHiVoltageInfoReceived(const Enercom::Network::Packet::Fields::Ptr& data);

        /**
         * Emits, when device low voltage info received
         * @param data packet data
         */
        void deviceLoVoltageInfoReceived(const Enercom::Network::Packet::Fields::Ptr& data);

        /**
         * Emits, when calibrator voltage info received
         * @param data packet data
         */
        void deviceCalibratorInfoReceived(const Enercom::Network::Packet::Fields::Ptr& data);

    public slots:
        /**
        * Incoming packet handler
        * @param packet response data
        */
        void onIncomingPacket(const Enercom::Network::Packet::Fields::Ptr& packet);

        /**
        * Incoming broadcast packet handler
        * @param packet response data
        */
        void onIncomingBroadcastPacket(const Enercom::Network::Packet::Fields::Ptr& packet);
    };

}
