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

        rows: engine.device.loVoltageInfo === null ? [] : [

            {
                "title": "Авторегулятор напряжения",
                "value": engine.device.loVoltageInfo.regulatorMode ? "Включен" : "Выключен"
            },

            {
                "title": "Задание регулятору, В",
                "value": engine.device.loVoltageInfo.regulatorVoltage
            },

            {
                "title": "Задание ЦАП, В",
                "value": engine.device.loVoltageInfo.dacVoltage
            },

            {
                "title": "Мин. напряжение установки, В",
                "value": engine.device.loVoltageInfo.regulatorVoltageMin
            },

            {
                "title": "Макс. напряжение, В",
                "value": engine.device.loVoltageInfo.regulatorVoltageMax
            },

            {
                "title": "Мин. напряжение ЦАП, В",
                "value": engine.device.loVoltageInfo.dacVoltageMin
            },

            {
                "title": "Макс. напряжение ЦАП, В",
                "value": engine.device.loVoltageInfo.dacVoltageMax
            },

            {
                "title": "Аттенюатор усилителя",
                "value": engine.device.loVoltageInfo.attenuator ? "Включен" : "Выключен"
            },

            {
                "title": "Коэффициент усилителя",
                "value": engine.device.loVoltageInfo.amplifierRatio
            },

            {
                "title": "Требуемая точность, %",
                "value": engine.device.loVoltageInfo.accuracy
            },

            {
                "title": "Коэффициент пропорциональности",
                "value": engine.device.loVoltageInfo.regulatorRatio
            },

            {
                "title": "Калибровка регулятора (множитель)",
                "value": engine.device.loVoltageInfo.calibrationFactor
            },

            {
                "title": "Калибровка регулятора (смещение)",
                "value": engine.device.loVoltageInfo.calibrationOffset
            }
        ]
    }
}