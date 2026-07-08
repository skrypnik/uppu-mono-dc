#pragma once

#include <QObject>

namespace Enercom::Model
{
    /**
    * Protocol model
    */
    class PacketModel;

    /**
     * Model collection
     */
    class Module final : public QObject
    {
        Q_OBJECT

        /**
        * Packet model
        */
        Q_PROPERTY( QVariant packetModel READ packet CONSTANT )

    public:
        /**
         * Constructs model collection
         * @param parent parent QObject to call safe deleter
         */
        explicit Module(QObject* parent = nullptr);

        /**
         * Packet model getter
         * @return protocol model pointer
         */
        [[nodiscard]] const PacketModel* packetModel() const;

    private:
        /**
        * Packet model metaobject property getter
        * @return protocol model pointer
        */
        [[nodiscard]] QVariant packet() const;

    private:
        /**
         * Packet model
         */
        PacketModel* packetModel_;
    };

}
