#pragma once

#include <QUdpSocket>
#include <QTimer>

namespace Enercom::Network
{
    class Searcher final : public QTimer
    {
        Q_OBJECT

    public:
        explicit Searcher(QObject* parent = nullptr);

        /**
         * Initializes searcher with given port
         * @param port network port
         */
        void initialize(uint16_t port);

    private:
        QUdpSocket* socket_;
    };

}
