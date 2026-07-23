#pragma once

#include <QAbstractListModel>

#include <network/Packet.h>

#include "MeterItem.h"

namespace Enercom::Model
{
    /**
     * Meter model, stores result of meter info requests
     */
    class MeterModel final : public QAbstractListModel
    {
        Q_OBJECT

    public:
        /**
         * Constructs meter model
         * @param parent parent QObject to call safe deleter
         */
        explicit MeterModel(QObject* parent = nullptr);

    private:
        /**
         * Appends or changes meter info model data
         * @param data response packet data
         * @return model item
         */
        MeterItem::Ptr incomingMeterInfo(const Enercom::Network::Packet::Fields::Ptr& data);

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

    signals:
        /**
         * Emits, when current meter info changed
         * @param info
         */
        void meterInfoChanged(const Enercom::Model::MeterItem::Ptr& info);

    public slots:
        /**
         * Incoming meter info handler
         * @param data response packet data
         */
        void onMeterInfoChanged(const Enercom::Network::Packet::Fields::Ptr& data);

        /**
         * Clears model data
         */
        void onClearModel();

    private:
        /**
         * Model data, meter items
         */
        std::vector<MeterItem::Ptr> items_;
    };

}
