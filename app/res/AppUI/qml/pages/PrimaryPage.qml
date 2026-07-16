import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimPage {

    SimFrame {

        id: panel

        height: SimControl.Size._40px

        anchors { left: parent.left; top: parent.top; right: parent.right; margins: SimControl.Margin._12px }

        SimLabel {

            id: title

            anchors { left: parent.left; verticalCenter: parent.verticalCenter }

            font { pixelSize: SimControl.Size._24px; weight: Font.DemiBold }

            text: "УППУ МОНО DC"
        }

        SimLabel {

            anchors { left: title.right; bottom: title.bottom; leftMargin: SimControl.Margin._08px }

            font { pixelSize: SimControl.Font._16px; weight: Font.DemiBold }

            text: engine.device.info ? engine.device.info.address0 : ""
        }

        SimMiniature {

            anchors { verticalCenter: parent.verticalCenter; right: parent.right; rightMargin: SimControl.Margin._02px }

            icon: "qrc:/SimDS/svg/controls/Close.svg"

            onClicked: {

                /// \todo
            }
        }
    }

    SimPanel {

        id: deviceInfo

        anchors { left: parent.left; top: panel.bottom; leftMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        controls: SimPanel.Controls.Edit

        title: "Информация об устройстве"

        Column {

            DeviceInfoView {

            }
        }

        onEdit: {

            networkInfoDialog.visible = true
        }
    }

    SimPanel {

        id: deviceStatusInfo

        anchors { left: deviceInfo.right; top: panel.bottom; leftMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        title: "Статус устройства"

        Column {

            DeviceStatusInfoView {

            }
        }
    }

    SimPanel {

        id: deviceHiVoltageInfo

        anchors { right: parent.right; top: panel.bottom; rightMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        title: "Параметры высокого напряжения"

        Column {

            DeviceHiVoltageInfoView {

            }
        }
    }

    SimPanel {

        id: deviceLoVoltageInfo

        anchors { right: parent.right; top: deviceHiVoltageInfo.bottom; rightMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        title: "Параметры низкого напряжения"

        Column {

            DeviceLoVoltageInfoView {

            }
        }
    }

    SimPanel {

        id: deviceCalibratorInfo

        anchors { left: parent.left; top: deviceInfo.bottom; leftMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        title: "Параметры калибратора"

        Column {

            DeviceCalibratorInfoView {

            }
        }
    }

    SimPanel {

        id: deviceMetersInfo

        anchors { left: parent.left; top: deviceCalibratorInfo.bottom; leftMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        controls: SimPanel.Controls.Edit

        title: "Параметры счетчиков"

        Column {

            DeviceMetersInfoView {

            }
        }

        onEdit: {

            metersInfoDialog.visible = true
        }
    }

    MetersInfoDialog {

        id: metersInfoDialog

        x: (parent.width - width) / 2.0; y: (parent.height - height) / 2.0

        visible: false
    }

    NetworkInfoDialog {

        id: networkInfoDialog

        x: (parent.width - width) / 2.0; y: (parent.height - height) / 2.0

        visible: false
    }

}
