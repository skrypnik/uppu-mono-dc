import Qt.labs.qmlmodels 1.0

import QtQuick 2.7

import SimDS 1.0

SimPropertyView {

    id: table

    model: TableModel {

        TableModelColumn {

            display: "title"
        }

        TableModelColumn {

            display: "value"
        }

        rows: engine.device.statusInfo === null ? [] : [

            {
                "title": "Статус готовности (ВН)",
                "value": engine.device.statusInfo.hiVoltageReady ? "Да" : "Нет"
            },

            {
                "title": "Статус генерации (ВН)",
                "value": engine.device.statusInfo.hiVoltageGeneration ? "Включена" : "Выключена"
            },

            {
                "title": "Выходное напряжение (ВН), В",
                "value": engine.device.statusInfo.hiVoltage
            },

            {
                "title": "Выходное напряжение ЦАП (ВН), В",
                "value": engine.device.statusInfo.hiVoltageDAC
            },

            {
                "title": "Напряжение на входе АЦП (ВН), В",
                "value": engine.device.statusInfo.hiVoltageADC
            },

            {
                "title": "Статус готовности (НН)",
                "value": engine.device.statusInfo.loVoltageReady ? "Да" : "Нет"
            },

            {
                "title": "Статус генерации (НН)",
                "value": engine.device.statusInfo.loVoltageGeneration ? "Включена" : "Выключена"
            },

            {
                "title": "Выходное напряжение (НН), В",
                "value": engine.device.statusInfo.loVoltage
            },

            {
                "title": "Выходное напряжение ЦАП (НН), В",
                "value": engine.device.statusInfo.loVoltageDAC
            },

            {
                "title": "Напряжение на входе АЦП (НН), В",
                "value": engine.device.statusInfo.loVoltageADC
            }
        ]
    }
}
