#include "DeviceModel.h"

#include <QDebug>

namespace Enercom::Model
{
    DeviceModel::DeviceModel(QObject* parent)
        : QAbstractListModel(parent)
    {

    }

    QVariant DeviceModel::data(const QModelIndex& index, const int role) const
    {
        if (!index.isValid()) return {};

        if (role == Qt::DisplayRole + 0x01) return QVariant::fromValue(items_.at(index.row()).get());

        return {};
    }

    int DeviceModel::rowCount(const QModelIndex& parent) const
    {
        return static_cast<int>(items_.size());
    }

    QHash<int, QByteArray> DeviceModel::roleNames() const
    {
        QHash<int, QByteArray> roles;
        roles.insert(Qt::DisplayRole + 0x01, "item");
        return roles;
    }

    void DeviceModel::onDeviceInfoChanged(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        const auto row = static_cast<int>(items_.size());

        this->beginInsertRows(QModelIndex(), row, row);
        auto item = DeviceItem::fromRawData(data->data()->data());
        items_.emplace(data->sn(), item);
        this->endInsertRows();

        emit this->dataChanged(this->index(row, 0), this->index(row, 0));

        emit this->deviceInfoChanged(item);
    }

}
