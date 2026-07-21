#include "ReportTemplate.h"

namespace SimSDK {

    ReportTemplate::ReportTemplate()
        : QDomDocument()
    {

    }

    void ReportTemplate::fromMap(const QVariantMap& data)
    {
        data_ = data;
    }

    void ReportTemplate::fromJson(const QJsonObject& json)
    {
        data_ = json.toVariantMap();
    }

    QString ReportTemplate::html() {

        this->createReport();

        return this->toString();
    }

    QDomElement ReportTemplate::createTable()
    {
        auto table = this->createElement("table");
        table.setAttribute("align", "left");
        table.setAttribute("border", 1);
        table.setAttribute("cellpadding", 4);

        return table;
    }

    QDomElement ReportTemplate::createTableBody()
    {
        return this->createElement("tbody");
    }

    void ReportTemplate::appendTableHeader(QDomElement& table, const QStringList& columns)
    {
        auto thead = this->createElement("thead");

        auto tr = this->createElement("tr");
        thead.appendChild(tr);

        auto fill = [ & ] (const QString& columnName) {

            auto name = this->createElement("th");
            name.setAttribute("align", "left");
            name.setAttribute("scope", "col");
            name.appendChild(this->createTextNode(columnName));
            tr.appendChild(name);
        };

        std::for_each(columns.begin(), columns.end(), fill);

        table.appendChild(thead);
    }

    auto ReportTemplate::appendTableRecord(QDomElement& body, const QStringList& columns) -> void
    {
        auto tr = this->createElement("tr");

        auto fill = [ & ] (const QString& columnName) {

            auto name = this->createElement("td");
            name.setAttribute("align", "left");
            name.setAttribute("scope", "col");
            name.appendChild(this->createTextNode(columnName));
            tr.appendChild(name);
        };

        std::for_each(columns.begin(), columns.end(), fill);

        body.appendChild(tr);
    }

}
