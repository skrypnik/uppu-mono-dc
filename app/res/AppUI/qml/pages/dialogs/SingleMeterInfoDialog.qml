import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimDialog {

    id: dialog

    property int index

    property alias address:  address.input
    property alias current:  current.input
    property alias voltage:  voltage.input
    property alias constant: constant.input
    property alias pulse:    pulse.combo.currentIndex

    title: "Параметры счетчика №" + (metersPanel.currentMeter.index + 0x01)

    SimFrame {

        Column {

            spacing: SimControl.Spacing._14px

            SimComboBox {

                id: pulse

                combo.model: [ "Автоматически", "Принудительно" ]

                title.text: "Выбор коэффициента"
            }

            Row {

                spacing: SimControl.Spacing._14px

                Column {

                    SimInputBox {

                        id: address

                        title.text: "MODBUS адрес"
                    }

                    SimInputBox {

                        id: current

                        title.text: "Номинальный ток, А"
                    }
                }

                Column {

                    SimInputBox {

                        id: voltage

                        title.text: "Напряжение, В"
                    }

                    SimInputBox {

                        id: constant

                        title.text: "Постоянная, имп/кВт*ч"
                    }
                }
            }
        }
    }

    onAccept: {

        let index = parseInt(dialog.index)
        let address = parseInt(dialog.address.text)
        let current = parseFloat(dialog.current.text)
        let voltage = parseFloat(dialog.voltage.text)
        let constant = parseInt(dialog.constant.text)
        let pulse = parseInt(dialog.pulse)

        engine.network.sendSetGivenMeterRequest(index, address, current, voltage, constant, pulse)
    }

    onVisibleChanged: {

        dialog.index = metersPanel.currentMeter.index

        pulse.combo.currentIndex = metersPanel.currentMeter.pulse
        address.input.text = metersPanel.currentMeter.address
        current.input.text = metersPanel.currentMeter.current
        voltage.input.text = metersPanel.currentMeter.voltage
        constant.input.text = metersPanel.currentMeter.constant
    }
}