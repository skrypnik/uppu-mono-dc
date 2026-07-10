import QtQuick.Controls 2.15
import QtQuick 2.7

import SimDS 1.0

GroupBox {

    id: control

    signal close()

    leftPadding: SimControl.Padding._14px; topPadding: SimControl.Padding._14px + label.height; rightPadding: SimControl.Padding._14px; bottomPadding: SimControl.Padding._14px

    background: Rectangle {

        color: SimPalette.colors.grey[1400]

        border.color: SimPalette.colors.grey[1300]
    }

    label: Rectangle {

        width: parent.width; height: SimControl.Size._40px

        color: SimPalette.colors.grey[1600]

        border.color: SimPalette.colors.grey[1300]

        Text {

            anchors { verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: SimControl.Margin._12px }

            font { pixelSize: SimControl.Font._19px; weight: Font.Medium }

            color: SimPalette.colors.grey[0]

            text: control.title
        }

        SimMidgetButton {

            anchors { verticalCenter: parent.verticalCenter; right: parent.right; rightMargin: SimControl.Margin._12px }

            icon: "qrc:/SimDS/svg/controls/Close.svg"

            onClicked: close()
        }
    }
}
