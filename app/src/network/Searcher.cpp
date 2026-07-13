#include "Searcher.h"

namespace Enercom::Network
{
    Searcher::Searcher(QObject* parent)
        : QTimer(this)
        , socket_(new QUdpSocket(this))
    {

    }

    void Searcher::initialize(uint16_t port)
    {

    }
}
