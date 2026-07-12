import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimPage {

    SimWindow {

        anchors.centerIn: parent

        title: "Подключение к устройству"

        Column {

            spacing: SimControl.Spacing._40px

            Row {

                spacing: SimControl.Spacing._40px

                Column {

                    id: network

                    spacing: SimControl.Spacing._14px

                    SimFrame {

                        Column {

                            spacing: SimControl.Spacing._08px

                            property alias hostInput: host.input
                            property alias portInput: port.input

                            SimInputBox {

                                id: host

                                title.text: "Адрес устройства"

                                input.text: engine.config.connectionHost
                            }

                            SimInputBox {

                                id: port

                                title.text: "Сетевой порт"

                                input.text: engine.config.connectionPort
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

                ObservedDeviceView {

                    id: devices

                    onSelectedChanged: {

                        host.input.text = item.address0
                        port.input.text = item.port0
                    }

                    width: 228.0; height: network.height
                }
            }
        }

        onClose: Qt.quit()
    }
}
