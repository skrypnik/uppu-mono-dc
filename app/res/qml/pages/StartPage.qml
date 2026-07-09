import QtQuick 2.7

import SimDS 1.0

import "views"

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

                                title.text: "Адрес устройства"

                                input.text: engine.config.connectionHost
                            }

                            SimInputBox {

                                title.text: "Сетевой порт"

                                input.text: engine.config.connectionPort
                            }
                        }
                    }

                    SimButton {

                        width: network.width

                        text: "Подключиться"
                    }
                }

                SimFrame {

                    id: devices

                    width: 228.0; height: network.height

                    SimSpinner { anchors.centerIn: parent }
                }
            }
        }
    }
}
