import QtQuick 2.7

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

                SimFrame {

                    id: devices

                    width: 228.0; height: network.height

                    SimSpinner { anchors.centerIn: parent }
                }
            }
        }

        onClose: Qt.quit()
    }
}
