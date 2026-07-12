import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimPage {

    SimPanel {

        anchors { left: parent.left; top: parent.top; leftMargin: SimControl.Margin._12px; topMargin: SimControl.Margin._12px }

        title: "Информация об устройстве"

        Column {

            DeviceInfoView {

            }
        }
    }
}
