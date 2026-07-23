#include "MeterModel.h"

#include <QDebug>

namespace Enercom::Model
{
    MeterModel::MeterModel(QObject* parent)
        : QAbstractListModel(parent)
    {

    }

    MeterItem::Ptr MeterModel::incomingMeterInfo(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        auto item = MeterItem::fromRawData(data->data()->data());

        for (int row=0x00; row<items_.size(); ++row)
        {
            if (item->index_ == items_[row]->index_)
            {
                items_[row] = item;

                emit this->dataChanged(this->index(row, 0), this->index(row, 0));

                return item;
            }
        }

        const auto row = static_cast<int>(items_.size());

        this->beginInsertRows(QModelIndex(), row, row);
        items_.emplace_back(item);
        this->endInsertRows();

        emit this->dataChanged(this->index(row, 0), this->index(row, 0));

        return item;
    }

    QVariant MeterModel::data(const QModelIndex& index, const int role) const
    {
        if (!index.isValid()) return {};

        if (role == Qt::DisplayRole + 0x01) return QVariant::fromValue(items_.at(index.row()).get());

        return {};
    }

    int MeterModel::rowCount(const QModelIndex& parent) const
    {
        return static_cast<int>(items_.size());
    }

    QHash<int, QByteArray> MeterModel::roleNames() const
    {
        QHash<int, QByteArray> roles;
        roles.insert(Qt::DisplayRole + 0x01, "item");
        return roles;
    }

    void MeterModel::onMeterInfoChanged(const Enercom::Network::Packet::Fields::Ptr& data)
    {
        const auto& item = this->incomingMeterInfo(data);

        emit this->meterInfoChanged(item);
    }

    void MeterModel::onClearModel()
    {
        const auto lastIndex = static_cast<int>(items_.size() - 0x01);

        this->beginRemoveRows(QModelIndex(), 0x00, lastIndex);
        items_.clear();
        this->endRemoveRows();
    }
}
