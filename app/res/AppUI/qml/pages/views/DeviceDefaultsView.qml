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

        rows: engine.device.calibratorInfo === null ? [] : [

            {
                "title": "Сетевой адрес",
                "value": engine.device.defaults.address
            },

            {
                "title": "Сетевая маска",
                "value": engine.device.defaults.netmask
            },

            {
                "title": "Сетевой порт",
                "value": engine.device.defaults.port
            },

            {
                "title": "Серийный номер",
                "value": engine.device.defaults.serial
            },

            {
                "title": "MAC адрес",
                "value": engine.device.defaults.mac
            }
        ]
    }
}