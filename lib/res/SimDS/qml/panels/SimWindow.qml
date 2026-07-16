import QtQuick.Controls 2.15
import QtQuick 2.7

import SimDS 1.0

GroupBox {

    id: control

    signal close()

    Drag.active: dragArea.drag.active
    Drag.hotSpot.x: 10.0
    Drag.hotSpot.y: 10.0

    leftPadding: SimControl.Padding._14px; topPadding: SimControl.Padding._14px + label.height; rightPadding: SimControl.Padding._14px; bottomPadding: SimControl.Padding._14px

    background: Rectangle {

        color: SimPalette.colors.grey[1400]

        border.color: SimPalette.colors.grey[1300]
    }

    label: Rectangle {

        width: parent.width; height: SimControl.Size._40px

        color: SimPalette.colors.grey[1600]

        border.color: SimPalette.colors.grey[1300]

        MouseArea {

            id: dragArea

            anchors { fill: parent }

            drag.target: control
        }

        Text {

            anchors { verticalCenter: parent.verticalCenter; left: parent.left; leftMargin: SimControl.Margin._12px }

            font { pixelSize: SimControl.Font._19px; weight: Font.DemiBold }

            color: SimPalette.colors.grey[0]

            text: control.title
        }

        SimMiniature {

            anchors { verticalCenter: parent.verticalCenter; right: parent.right; rightMargin: SimControl.Margin._12px }

            icon: "qrc:/SimDS/svg/controls/Close.svg"

            onClicked: close()
        }
    }
}
