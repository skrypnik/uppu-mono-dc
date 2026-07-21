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

        rows: engine.device.calibratorReadings === null ? [] : [

            {
                "title": "Значение высокого напряжения, В",
                "value": engine.device.calibratorReadings.voltage
            },

            {
                "title": "Значение тока, А",
                "value": engine.device.calibratorReadings.current
            },

            {
                "title": "Значение мощности, Вт",
                "value": engine.device.calibratorReadings.power
            },

            {
                "title": "Значение энергии, кВт*ч",
                "value": engine.device.calibratorReadings.energy
            },

            {
                "title": "Значение периода импульсов, сек",
                "value": engine.device.calibratorReadings.pulsePeriod
            },

            {
                "title": "Количество выданных импульсов",
                "value": engine.device.calibratorReadings.pulseCount
            }
        ]
    }
}
