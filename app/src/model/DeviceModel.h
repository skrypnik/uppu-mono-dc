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

    private:
        /**
         * Appends or changes device info model data
         * @param data response packet data
         * @return model item
         */
        DeviceItem::Ptr incomingDeviceInfo(const Enercom::Network::Packet::Fields::Ptr& data);

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
         * Emits, when current device info changed
         * @param info
         */
        void deviceInfoChanged(const Enercom::Model::DeviceItem::Ptr& info);

    public slots:
        /**
         * Incoming device info handler (from TCP request)
         * @param data response packet data
         */
        void onDeviceInfoChanged(const Enercom::Network::Packet::Fields::Ptr& data);

        /**
         * Incoming device info handler  (from broadcast UDP request)
         * @param data response packet data
         */
        void onIncomingDeviceInfo(const Enercom::Network::Packet::Fields::Ptr& data);

    private:
        /**
         * Model data, device items
         */
        std::vector<DeviceItem::Ptr> items_;
    };

}
