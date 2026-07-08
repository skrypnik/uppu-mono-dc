#include "DataView.h"

namespace Enercom::Model
{
    DataView::DataView(QObject* parent)
        : QObject(parent)
    {
    }

    /*static*/ QStringList DataView::toHexView(const QByteArray& data)
    {
        QStringList view;

        for (const auto& byte : data)
        {
            const auto bytes = QString(QByteArray::fromRawData(&byte, 0x01).toHex()).toUpper();
            view.append(bytes);
        }

        return view;
    }

    DataView::Ptr DataView::create(const QByteArray& type, const QByteArray& size, const QByteArray& data)
    {
        auto ptr = std::make_shared<DataView>();

        ptr->type_ = DataView::toHexView(type);
        ptr->size_ = DataView::toHexView(size);
        ptr->data_ = DataView::toHexView(data);

        return ptr;
    }

    const QStringList& DataView::type() const
    {
        return type_;
    }

    const QStringList& DataView::size() const
    {
        return size_;
    }

    const QStringList& DataView::data() const
    {
        return data_;
    }
}
