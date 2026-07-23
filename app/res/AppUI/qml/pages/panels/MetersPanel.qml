import Qt.labs.qmlmodels 1.0

import QtQuick.Layouts 1.15
import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

ListView {

    id: metersView

    property QtObject currentMeter

    width: parent.width; height: count * 200.0

    model: engine.model.meterModel

    delegate: SimPanel {

        readonly property int number: item.index

        controls: SimPanel.Controls.Edit

        title: "Счетчик №" + number

        Column {

            SimPropertyView {

                model: TableModel {

                    TableModelColumn {

                        display: "title"
                    }

                    TableModelColumn {

                        display: "value"
                    }

                    rows: item === null ? [] : [

                        {
                            "title": "MODBUS адрес",
                            "value": item.address
                        },

                        {
                            "title": "Номинальный ток, А",
                            "value": item.current
                        },

                        {
                            "title": "Напряжение, В",
                            "value": item.voltage
                        },

                        {
                            "title": "Постоянная, имп/кВт*ч",
                            "value": item.constant
                        },

                        {
                            "title": "Выбор импульсного коэффициента",
                            "value": item.pulse ? "Принудительно" : "Автоматически"
                        }

                    ]
                }
            }
        }

        onEdit: {

            metersView.currentMeter = item
            singleMeterInfoDialog.visible = true
        }
    }
}