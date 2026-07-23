import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimDialog {

    title: "Настройки по умолчанию"

    SimFrame {

            Column {

                SimInputBox {

                    id: host

                    title.text: "Сетевой адрес"

                    input.validator: RegExpValidator {

                        regExp: /[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}/
                    }
                }

                SimInputBox {

                    id: mask

                    title.text: "Сетевая маска"

                    input.validator: RegExpValidator {

                        regExp: /[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}/
                    }
                }

                SimInputBox {

                    id: port

                    title.text: "Сетевой порт"

                    input.validator: IntValidator {

                        bottom: 1; top: 65534
                    }
                }

                SimInputBox {

                    id: serial

                    title.text: "Серийный номер"

                    input.validator: IntValidator {

                        bottom: 1; top: 65534
                    }
                }

                SimInputBox {

                    id: mac

                    title.text: "MAC адрес"
                }
            }
    }

    onAccept: {

        let nPort = parseInt(port.input.text)
        let nSerial = parseInt(serial.input.text)

        engine.network.sendSetDefaultParamsRequest(host.input.text, mask.input.text, nPort, nSerial, mac.input.text, 0, '9627189653')
    }

    onVisibleChanged: {

        if (!visible) return

        host.input.text = engine.device.defaults.address
        mask.input.text = engine.device.defaults.netmask
        port.input.text = engine.device.defaults.port
        serial.input.text = engine.device.defaults.serial
        mac.input.text = engine.device.defaults.mac
    }
}