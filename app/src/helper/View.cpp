#include "View.h"

namespace Enercom
{
    QString Helper::View::normalizedFloat(const float value, const int precision)
    {
        return QString::number(value, 'f', precision).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }

    QString Helper::View::normalizedFloat(const double value, const int precision)
    {
        return QString::number(value, 'f', precision).remove( QRegExp("0+$") ).remove( QRegExp("\\.$") );
    }
} // Enercom