#pragma once

#include <QDomDocument>
#include <QJsonObject>

namespace SimSDK {

    /**
     * @brief The ReportTemplate class
     *
     * Report template interface
     */
    class ReportTemplate : public QDomDocument
    {
        friend class ReportGenerator;

    public:
        /**
         * @brief ReportTemplate
         *
         * Constructs default object
         */
        ReportTemplate();

        /**
         * @brief fromMap sets report from data map
         * @param data report data map
         */
        void fromMap(const QVariantMap& data);

        /**
         * @brief fromJson sets report from JSON object
         * @param json report data map
         */
        void fromJson(const QJsonObject& json);

        /**
         * @brief html generates html from DOM data
         * @return generated html
         */
        QString html();

    protected:
        /**
         * Virtual destructor does not hides QDomDocument
         */
        ~ReportTemplate() = default;

        /**
         * @brief createReport
         *
         * Overload it to create report from report data map
         */
        virtual void createReport() = 0;

    protected:
        /**
         * Creates table DOM
         * @return table DOM element
         */
        QDomElement createTable();

        /**
         * Creates table body DOM
         * @return table body DOM element
         */
        QDomElement createTableBody();

        /**
         * Appends header DOM to table
         * @param table table DOM element
         * @param columns column names
         */
        auto appendTableHeader(QDomElement& table, const QStringList& columns) -> void;

        /**
         * Appends record DOM to table
         * @param body table body DOM element
         * @param columns record column data
         */
        auto appendTableRecord(QDomElement& body, const QStringList& columns) -> void;

    protected:
        /**
         * @brief data_
         *
         * Map that contains report data to html generation
         */
        QVariantMap data_;
    };

}
