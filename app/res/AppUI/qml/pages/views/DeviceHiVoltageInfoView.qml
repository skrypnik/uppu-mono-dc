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

        rows: engine.device.hiVoltageInfo === null ? [] : [

            {
                "title": "Авторегуляция напряжения",
                "value": engine.device.hiVoltageInfo.regulatorMode
            },

            {
                "title": "Задание регулятору, В",
                "value": engine.device.hiVoltageInfo.regulatorVoltage
            },

            {
                "title": "Задание ЦАП, В",
                "value": engine.device.hiVoltageInfo.dacVoltage
            },

            {
                "title": "Мин. напряжение установки, В",
                "value": engine.device.hiVoltageInfo.regulatorVoltageMin
            },

            {
                "title": "Макс. напряжение, В",
                "value": engine.device.hiVoltageInfo.regulatorVoltageMax
            },

            {
                "title": "Мин. напряжение ЦАП, В",
                "value": engine.device.hiVoltageInfo.dacVoltageMin
            },

            {
                "title": "Макс. напряжение ЦАП, В",
                "value": engine.device.hiVoltageInfo.dacVoltageMax
            },

            {
                "title": "Коэффициент деления",
                "value": engine.device.hiVoltageInfo.dividerRatio
            },

            {
                "title": "Требуемая точность, %",
                "value": engine.device.hiVoltageInfo.accuracy
            },

            {
                "title": "Коэффициент пропорциональности",
                "value": engine.device.hiVoltageInfo.regulatorRatio
            },

            {
                "title": "Калибровка регулятора (множитель)",
                "value": engine.device.hiVoltageInfo.calibrationFactor
            },

            {
                "title": "Калибровка регулятора (смещение)",
                "value": engine.device.hiVoltageInfo.calibrationOffset
            }
        ]
    }
}
