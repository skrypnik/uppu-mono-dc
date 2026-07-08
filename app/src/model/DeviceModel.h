#pragma once

#include <QAbstractListModel>

#include <network/Packet.h>

#include "DeviceItem.h"

namespace Enercom::Model
{
    /**
     * Device model, stores result of broadcast device info request
     */
    class DeviceModel final : public QAbstractListModel
    {
        Q_OBJECT

    public:
        /**
         * Constructs device model
         * @param parent parent QObject to call safe deleter
         */
        explicit DeviceModel(QObject* parent = nullptr);

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
         * Outgoing data handler
         * @param data response raw data
         */
        void onIncomingData(const Enercom::Network::Packet::Fields::Ptr& data);

    private:
        /**
         * Model data, device items
         */
        std::vector<DeviceItem::Ptr> items_;
    };

}
