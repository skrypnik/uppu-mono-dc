#pragma once

#include <QRegExp>

namespace Enercom::Helper
{
    /**
     * Data view helper
     */
    class View
    {

    public:
        /**
         * Returns floating point value normalized view
         * @param value floating point value
         * @param precision precision after point
         * @return normalized view
         */
        static QString normalizedFloat(float value, int precision = 6);

        /**
         * Returns floating point value normalized view
         * @param value floating point value
         * @param precision precision after point
         * @return normalized view
         */
        static QString normalizedFloat(double value, int precision = 6);
    };

}