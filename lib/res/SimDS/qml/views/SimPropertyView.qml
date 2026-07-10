import Qt.labs.qmlmodels 1.0

import QtQuick 2.14

import SimDS 1.0

TableView {

    id: table

    width: 360.0 + SimControl.Spacing._01px; height: rows * SimControl.Size._32px + rows * rowSpacing

    columnSpacing: SimControl.Spacing._01px; rowSpacing: SimControl.Spacing._01px

    clip: true

    delegate: Rectangle {

        implicitWidth: column === 0x00 ? 200.0 : 160.0; implicitHeight: SimControl.Size._32px

        color: column === 0x00 ? SimPalette.colors.grey[1500] : SimPalette.colors.grey[1400]

        border { color: SimPalette.colors.grey[1300] }

        SimLabel {

            anchors { left: parent.left; leftMargin: SimControl.Margin._08px; verticalCenter: parent.verticalCenter }

            text: display
        }
    }
}