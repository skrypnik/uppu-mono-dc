import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimDialog {

    id: dialog

    property int voltageKind: VoltageInfoDialog.VoltageKind.Low

    enum VoltageKind {

        Low  = 0x00,
        High = 0x01
    }

    title: voltageKind === VoltageInfoDialog.VoltageKind.Low ? "Низкое напряжение" : "Высокое напряжение"

    SimFrame {

        Column {

            spacing: SimControl.Spacing._14px

            Row {

                spacing: SimControl.Spacing._14px

                SimLabel {

                    text: "Авторегуляция напряжения"
                }

                SimCheckBox {

                    id: autoregulator

                    checked: dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low ? engine.device.loVoltageInfo.regulatorMode : engine.device.hiVoltageInfo.regulatorMode
                }
            }

            SimInputBox {

                id: inputVoltage

                title.text: "Задание регулятору, В"

                /// \todo validator
            }

            SimInputBox {

                id: inputDACVoltage

                title.text: "Задание ЦАП, В"

                /// \todo validator
            }
        }
    }

    onAccept: {

        /// \todo check acceptable input

        let mode = autoregulator.checked
        let voltage = parseFloat(inputVoltage.input.text)
        let dacVoltage = parseFloat(inputDACVoltage.input.text)

        if (dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low) engine.network.sendSetLoVoltageInfoRequest(mode, voltage, dacVoltage)
        else engine.network.sendSetHiVoltageInfoRequest(mode, voltage, dacVoltage)
    }

    onVisibleChanged: {

        if (!visible) return

        let min = (dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low) ? engine.device.loVoltageInfo.regulatorVoltageMin : engine.device.hiVoltageInfo.regulatorVoltageMin
        let max = (dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low) ? engine.device.loVoltageInfo.regulatorVoltageMax : engine.device.hiVoltageInfo.regulatorVoltageMax
        inputVoltage.about.text = min + " - " + max

        min = (dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low) ? engine.device.loVoltageInfo.dacVoltageMin : engine.device.hiVoltageInfo.dacVoltageMin
        max = (dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low) ? engine.device.loVoltageInfo.dacVoltageMax : engine.device.hiVoltageInfo.dacVoltageMax
        inputDACVoltage.about.text = min + " - " + max

        inputVoltage.input.text = (dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low) ? engine.device.loVoltageInfo.regulatorVoltage : engine.device.hiVoltageInfo.regulatorVoltage
        inputDACVoltage.input.text = (dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low) ? engine.device.loVoltageInfo.dacVoltage : engine.device.hiVoltageInfo.dacVoltage
        autoregulator.checked = (dialog.voltageKind === VoltageInfoDialog.VoltageKind.Low) ? engine.device.loVoltageInfo.regulatorMode : engine.device.hiVoltageInfo.regulatorMode
    }
}