import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimDialog {

    title: "Параметры калибратора"

    SimFrame {

        Column {

            SimInputBox {

                id: constant

                title.text: "Постоянная, имп/кВт*ч"

                /// \todo validator

                about.text: "1 - 10000"
            }

            SimInputBox {

                id: current

                title.text: "Номинальный ток, А"

                /// \todo validator

                about.text: "1 - 10000"
            }

            SimInputBox {

                id: voltage

                title.text: "Напряжение, В"

                /// \todo validator

                about.text: "0.0 - 1.0"
            }
        }
    }

    onAccept: {

        /// \todo check acceptable input

        let fConstant = parseFloat(constant.input.text)
        let fCurrent = parseFloat(current.input.text)
        let fVoltage = parseFloat(voltage.input.text)

        /// \note first parameter equals to zero because only one mode are present
        engine.network.sendSetCalibratorInfoRequest(0x00, fConstant, fCurrent, fVoltage)
    }

    onVisibleChanged: {

        if (!visible) return

        constant.input.text = engine.device.calibratorInfo.constant
        current.input.text = engine.device.calibratorInfo.current
        voltage.input.text = engine.device.calibratorInfo.voltage
    }
}