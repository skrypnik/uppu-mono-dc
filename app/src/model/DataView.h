#pragma once

#include <QObject>

#include <memory>

namespace Enercom::Model
{
    /**
     * Data wrapper, implements TLV 2-digit hex view
     */
    class DataView final : public QObject
    {
        Q_OBJECT

        /**
         * Data type view metaobject property (T)
         */
        Q_PROPERTY( QStringList type READ type CONSTANT );

        /**
         * Data size view metaobject property (L)
         */
        Q_PROPERTY( QStringList size READ size CONSTANT );

        /**
         * Data view metaobject property (V)
         */
        Q_PROPERTY( QStringList data READ data CONSTANT );

    public:
        /**
        * Alias for shared_ptr
        */
        using Ptr = std::shared_ptr<DataView>;

    public:
        /**
         * Constructs packet wrapper object
         * @param parent parent QObject to call safe deleter
         */
        explicit DataView(QObject* parent = nullptr);

    public:
        /**
         * Converts each array byte to 2-digit hex view
         * @param data byte data
         * @return 2-digit hex view
         */
        static QStringList toHexView(const QByteArray& data);

        /**
         * Creates data wrapper from given data
         * @param type data type
         * @param size data size
         * @param data data
         * @return data wrapper object pointer
         */
        static DataView::Ptr create(const QByteArray& type, const QByteArray& size, const QByteArray& data);

    private:
        /**
         * Data type view metaobject getter (T)
         */
        [[nodiscard]] const QStringList& type() const;

        /**
         * Data size view metaobject getter (L)
         */
        [[nodiscard]] const QStringList& size() const;

        /**
         * Data view metaobject getter (V)
         */
        [[nodiscard]] const QStringList& data() const;

    private:
        /**
         * Data type view (T)
         */
        QStringList type_;

        /**
         * Data size view (L)
         */
        QStringList size_;

        /**
         * Data view (V)
         */
        QStringList data_;
    };

}