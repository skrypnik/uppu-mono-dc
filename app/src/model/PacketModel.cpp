#include "PacketModel.h"

#include <network/Packet.h>

#include <QDebug>
#include <memory>

namespace Enercom::Model
{
    PacketModel::PacketModel(QObject* parent)
    {

    }

    void PacketModel::append(const PacketItem::Ptr& data)
    {
        const auto row = static_cast<int>(data_.size());
        this->beginInsertRows(QModelIndex(), row, row);
        data_.emplace(row, data);
        this->endInsertRows();

        emit this->dataChanged(this->index(row, 0), this->index(row, 0));
    }

    QVariant PacketModel::data(const QModelIndex& index, const int role) const
    {
        if (!index.isValid()) return {};

        if (role == Qt::DisplayRole + 0x01) return QVariant::fromValue(data_.at(index.row()).get());

        return {};
    }

    int PacketModel::rowCount(const QModelIndex& parent) const
    {
        return static_cast<int>(data_.size());
    }

    QHash<int, QByteArray> PacketModel::roleNames() const
    {
        QHash<int, QByteArray> roles;
        roles.insert(Qt::DisplayRole + 0x01, "item");
        return roles;
    }

    void PacketModel::onOutgoingData(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        const auto item = std::make_shared<PacketItem>(data);
        this->append(item);
    }

    void PacketModel::onIncomingData(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        const auto item = std::make_shared<PacketItem>(data);
        this->append(item);
    }

}
