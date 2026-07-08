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

                spacing: SimControl.Spacing._14px

                SimGroupBox {

                    title: "Доступные устройства"

                    Column {

                        DeviceView {

                        }
                    }
                }

                SimGroupBox {

                    title: "Ввести вручную"

                    Column {

                        spacing: SimControl.Spacing._08px

                        SimInputBox {

                            id: host

                            title.text: "IP адрес устройства"
                        }

                        SimInputBox {

                            id: port

                            title.text: "Сетевой порт"
                        }
                    }
                }
            }

            SimButton {

                anchors { right: parent.right; rightMargin: SimControl.Spacing._14px }

                text: "Подключиться"
            }
        }
    }
}
