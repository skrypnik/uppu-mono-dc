import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimPage {

    SimWindow {

        x: (parent.width - width) / 2.0; y: (parent.height - height) / 2.0

        title: "Подключение к устройству"

        Column {

            spacing: SimControl.Spacing._14px

            Row {

                spacing: SimControl.Spacing._40px

                Column {

                    id: network

                    SimFrame {

                        Column {

                            spacing: SimControl.Spacing._08px

                            property alias hostInput: host.input
                            property alias portInput: port.input

                            SimInputBox {

                                id: host

                                title.text: "Адрес устройства"

                                input.text: engine.config.connectionHost

                                input.validator: RegExpValidator {

                                    regExp: /[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}/
                                }
                            }

                            SimInputBox {

                                id: port

                                title.text: "Сетевой порт"

                                input.text: engine.config.connectionPort

                                input.validator: IntValidator {

                                    bottom: 0; top: 65535
                                }
                            }
                        }
                    }
                }

                ObservedDeviceView {

                    id: devices

                    height: network.height

                    onSelectedChanged: {

                        host.input.text = item.address0
                        port.input.text = item.port0
                    }
                }
            }

            SimButton {

                width: network.width

                text: "Подключиться"

                onClicked: {

                    engine.network.setConnectionParams(host.input.text, port.input.text)
                    engine.network.connectToHost()
                }
            }
        }

        onClose: Qt.quit()
    }
}
