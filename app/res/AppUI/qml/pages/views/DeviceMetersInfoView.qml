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

        rows: engine.device.metersInfo === null ? [] : [

            {
                "title": "Количество счетчиков",
                "value": engine.device.metersInfo.count
            },

            {
                "title": "Скорость UART",
                "value": engine.device.metersInfo.baudRate
            },

            {
                "title": "Тип импульсного входа",
                "value": engine.device.metersInfo.inputKind ? "Проводной" : "УФС"
            },

            {
                "title": "Напряжение питания счетчиков, В",
                "value": engine.device.metersInfo.inputVoltage
            },

            {
                "title": "Выходное напряжение питания, В",
                "value": engine.device.metersInfo.outputVoltage
            }
        ]
    }
}