import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimPage {

    SimPanel {

        id: deviceInfo

        anchors { left: parent.left; top: parent.top; leftMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        title: "Информация об устройстве"

        Column {

            DeviceInfoView {

            }
        }
    }

    SimPanel {

        id: deviceStatusInfo

        anchors { left: deviceInfo.right; top: parent.top; leftMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        title: "Статус устройства"

        Column {

            DeviceStatusInfoView {

            }
        }
    }

    SimPanel {

        id: deviceHiVoltageInfo

        anchors { right: parent.right; top: parent.top; rightMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

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

}
