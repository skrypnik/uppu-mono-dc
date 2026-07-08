#pragma once

#include <QVariant>
#include <QObject>

namespace Enercom::Config
{
    class Module final : public QObject
    {
        Q_OBJECT

        /**
         * Application title
         */
        Q_PROPERTY( QVariant applicationTitle READ applicationTitle CONSTANT )

        /**
         * Connection host
         */
        Q_PROPERTY( QVariant connectionHost READ connectionHost CONSTANT )

        /**
         * Connection port
         */
        Q_PROPERTY( QVariant connectionPort READ connectionPort CONSTANT )

    public:
        /**
        * Constructs config module object
        * @param parent parent QObject to call safe deleter
        */
        explicit Module(QObject* parent = nullptr);

    private:
        /**
        * Application title metaobject property getter
        * @return application title
        */
        [[nodiscard]] QVariant applicationTitle() const;

        /**
        * Connection host metaobject property getter
        * @return connection host
        */
        [[nodiscard]] QVariant connectionHost() const;

        /**
        * Connection port metaobject property getter
        * @return connection port
        */
        [[nodiscard]] QVariant connectionPort() const;
    };

}