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
                "title": "Постоянная калибратора, имп/кВт*ч",
                "value": engine.device.calibratorInfo.constant
            },

            {
                "title": "Номинальный ток, А",
                "value": engine.device.calibratorInfo.current
            },

            {
                "title": "Напряжение, В",
                "value": engine.device.calibratorInfo.voltage
            }
        ]
    }
}