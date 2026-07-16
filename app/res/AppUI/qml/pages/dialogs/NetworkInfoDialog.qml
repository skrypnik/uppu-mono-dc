import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimDialog {

    title: "Параметры сети"

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
            }
    }

    onAccept: {

        if (!(host.input.acceptableInput && mask.input.acceptableInput && port.input.acceptableInput)) return

        let sHost = host.input.text
        let sMask = mask.input.text
        let nPort = parseInt(port.input.text)

        engine.network.sendSetNetworkInfoRequest(sHost, sMask, nPort)
    }

    onVisibleChanged: {

        if (!visible) return

        host.input.text = engine.device.info.address0
        mask.input.text = engine.device.info.netmask0
        port.input.text = engine.device.info.port0
    }
}