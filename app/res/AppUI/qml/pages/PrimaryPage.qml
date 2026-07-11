import Qt.labs.qmlmodels 1.0

import QtQuick 2.7

import SimDS 1.0

import "views"

SimPage {

    SimPanel {

        anchors { centerIn: parent }

        title: "Информация об устройстве"

        Column {

            SimPropertyView {

                id: table

                model: TableModel {

                    TableModelColumn {

                        display: "title"
                    }

                    TableModelColumn {

                        display: "value"
                    }

                    rows: engine.device.info === null ? [] : [

                        {
                            "title": "Серийный номер",
                            "value": engine.device.info.serial
                        },

                        {
                            "title": "Сетевой адрес (с)",
                            "value": engine.device.info.address0
                        },

                        {
                            "title": "Сетевая маска (с)",
                            "value": engine.device.info.netmask0
                        },

                        {
                            "title": "Сетевой порт (с)",
                            "value": engine.device.info.port0
                        },

                        {
                            "title": "Сетевой адрес (о)",
                            "value": engine.device.info.address1
                        },

                        {
                            "title": "Сетевая маска (о)",
                            "value": engine.device.info.netmask1
                        },

                        {
                            "title": "Сетевой порт (о)",
                            "value": engine.device.info.port1
                        },

                        {
                            "title": "Версия протокола",
                            "value": engine.device.info.protocol
                        },

                        {
                            "title": "Версия прошивки",
                            "value": engine.device.info.version
                        },

                        {
                            "title": "Дата сборки",
                            "value": engine.device.info.date
                        }
                    ]
                }
            }
        }
    }
}
