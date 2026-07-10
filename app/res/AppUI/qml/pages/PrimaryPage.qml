import Qt.labs.qmlmodels 1.0

import QtQuick 2.7

import SimDS 1.0

import "views"

SimPage {

    SimPanel {

        // width: 400.0; height: 400.0

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

                    rows: [

                        {
                            "title": "Серийный номер",
                            "value": "123"
                        },
                        {
                            "title": "Сетевой адрес",
                            "value": "192.168.138.11"
                        },
                        {
                            "title": "Сетевая маска",
                            "value": "255.255.0.0"
                        },
                        {
                            "title": "Сетевой порт",
                            "value": "63500"
                        }
                    ]
                }
            }
        }
    }
}
