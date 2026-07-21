#pragma once

#include <QObject>

namespace SimSDK {

    /**
     * @brief The ReportExample class
     *
     * Report generator
     */
    class ReportTemplate;

    /**
     * @brief The ReportGenerator class
     *
     * Generates report with given template
     */
    class ReportGenerator final : public QObject
    {
        Q_OBJECT

    public:
        /**
         * @brief ReportGenerator
         *
         * Constructs default object
         */
        explicit ReportGenerator(QObject* parent = nullptr);

        /**
         * @brief setReportTemplate
         * @param documentTemplate document template
         *
         * Sets document template
         */
        void setReportTemplate(const ReportTemplate* documentTemplate);

        /**
         * @brief generate
         * @param path path to output file
         *
         * Generates report document in PDF format
         */
        void saveToPdf(const QString& path) const;

    private:
        /**
         * @brief template_
         *
         * Document template
         */
        ReportTemplate* template_;
    };

}
