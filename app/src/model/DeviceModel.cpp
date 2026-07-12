#include "DeviceModel.h"

#include <QDebug>

namespace Enercom::Model
{
    DeviceModel::DeviceModel(QObject* parent)
        : QAbstractListModel(parent)
    {

    }

    DeviceItem::Ptr DeviceModel::incomingDeviceInfo(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        auto item = DeviceItem::fromRawData(data->data()->data());

        for (int row=0x00; row<items_.size(); ++row)
        {
            if (items_[row]->serial_ == item->serial_)
            {
                items_[row] = item;

                emit this->dataChanged(this->index(row, 0), this->index(row, 0));

                return item;
            }

            row++;
        }

        const auto row = static_cast<int>(items_.size());

        this->beginInsertRows(QModelIndex(), row, row);
        items_.emplace_back(item);
        this->endInsertRows();

        emit this->dataChanged(this->index(row, 0), this->index(row, 0));

        return item;
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
        const auto& item = this->incomingDeviceInfo(data);

        emit this->deviceInfoChanged(item);
    }

    void DeviceModel::onIncomingDeviceInfo(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        this->incomingDeviceInfo(data);
    }

}
