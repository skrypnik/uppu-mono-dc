#include "ReportGenerator.h"

#include <QTextDocument>
#include <QPrinter>
#include <QDebug>

#include "ReportTemplate.h"

namespace SimSDK {

    ReportGenerator::ReportGenerator(QObject* parent)
        : QObject(parent)
        , template_(nullptr)
    {

    }

    void ReportGenerator::setReportTemplate(const ReportTemplate* documentTemplate)
    {
        template_ = const_cast<ReportTemplate*>(documentTemplate);
    }

    void ReportGenerator::saveToPdf(const QString& path) const
    {
        if (template_ == nullptr)
        {
            qCritical() << Q_FUNC_INFO << "Cannot save pdf to empty report";

            return;
        }

        QTextDocument doc;
        doc.setHtml(template_->html());

        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(path);
        doc.print(&printer);
    }

}
