#pragma once

#include <QObject>

class QUdpSocket;

namespace Enercom::Network
{

    class Searcher final : public QObject
    {
        Q_OBJECT

    public:
        explicit Searcher(QObject* parent = nullptr);

        void startSearch(uint16_t port) const;

    private slots:
        void onDataAvailable() const;

    private:
        QUdpSocket* socket_;
    };

}
