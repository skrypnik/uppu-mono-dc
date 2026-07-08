#pragma once

#include <QAbstractListModel>

#include "PacketItem.h"

namespace Enercom::Model
{
    /**
     * Protocol model. Used in monitor view.
     */
    class PacketModel final : public QAbstractListModel
    {
        Q_OBJECT

    public:
        /**
         * Constructs packet model
         * @param parent parent QObject to call safe deleter
         */
        explicit PacketModel(QObject* parent = nullptr);

    private:
        /**
         * Appends data into model
         * @param data raw data
         */
        void append(const PacketItem::Ptr& data);

    protected:
        /**
         * Reimplemented QAbstractItemModel::data(const QModelIndex &index, int role) function
         */
        [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

        /**
         * Reimplemented QAbstractItemModel::rowCount(const QModelIndex &parent) function
         */
        [[nodiscard]] int rowCount(const QModelIndex &parent) const override;

        /**
         * Reimplemented QAbstractItemModel::roleNames() function
         */
        [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

    public slots:
        /**
         * Incoming data handler
         * @param data request raw data
         */
        void onOutgoingData(const Enercom::Network::Packet::Fields::Ptr& data);

        /**
         * Outgoing data handler
         * @param data response raw data
         */
        void onIncomingData(const Enercom::Network::Packet::Fields::Ptr& data);

    private:
        /**
         * Model data
         */
        std::map<int, PacketItem::Ptr> data_;
    };

}
