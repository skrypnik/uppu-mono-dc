import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimDialog {

    title: "Параметры счетчиков"

    SimFrame {

        Row {

            spacing: SimControl.Spacing._14px

            Column {

                SimInputBox {

                    id: metersCount

                    title.text: "Количество счетчиков"

                    input.validator: IntValidator {

                        bottom: 0; top: 3
                    }

                    about.text: "0 - 3"
                }

                SimInputBox {

                    id: inputVoltage

                    title.text: "Напряжение питания, В"

                    input.validator: DoubleValidator {

                        bottom: 10.0; top: 72.0
                    }

                    about.text: "10.0 - 72.0"
                }
            }

            Column {

                spacing: SimControl.Spacing._16px

                SimComboBox {

                    id: baudRate

                    combo.model: engine.device.metersInfo.availableSpeedValues

                    title.text: "Скорость, бит/с"
                }

                SimComboBox {

                    id: inputKind

                    combo.model: [ "УФС", "Проводной" ]

                    title.text: "Тип входа"
                }
            }
        }
    }

    onAccept: {

        if (!(metersCount.input.acceptableInput && inputVoltage.input.acceptableInput)) return

        let nCount = parseInt(metersCount.input.text)
        let fVoltage = parseFloat(inputVoltage.input.text)
        let nBaudRate = parseInt(baudRate.combo.currentValue)
        let nInputKind = parseInt(inputKind.combo.currentIndex)

        engine.network.sendSetMetersInfoRequest(nCount, nBaudRate, nInputKind, fVoltage)
    }

    onVisibleChanged: {

        if (!visible) return

        metersCount.input.text = engine.device.metersInfo.count
        inputVoltage.input.text = engine.device.metersInfo.inputVoltage
        inputKind.combo.currentIndex = engine.device.metersInfo.inputKind
        baudRate.combo.currentIndex = engine.device.metersInfo.baudRateIndex
    }
}