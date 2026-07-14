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
                "title": "Значение высокого напряжения, В",
                "value": engine.device.calibratorInfo.voltage
            },

            {
                "title": "Значение тока, А",
                "value": engine.device.calibratorInfo.current
            },

            {
                "title": "Значение мощности, Вт",
                "value": engine.device.calibratorInfo.power
            },

            {
                "title": "Значение энергии, кВт*ч",
                "value": engine.device.calibratorInfo.energy
            },

            {
                "title": "Значение периода импульсов, сек",
                "value": engine.device.calibratorInfo.pulsePeriod
            },

            {
                "title": "Количество выданных импульсов",
                "value": engine.device.calibratorInfo.pulseCount
            }
        ]
    }
}
