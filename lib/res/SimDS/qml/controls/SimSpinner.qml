import QtQuick 2.7

import SimDS 1.0

ListView {

    id: view

    property color color: SimPalette.colors.blue[700]

    width: SimControl.Size._32px + SimControl.Spacing._04px * 3.0; height: SimControl.Size._32px

    spacing: SimControl.Spacing._04px

    orientation: ListView.Horizontal

    model: 4

    delegate: Item {

        width: 8.0; height: 8.0

        Rectangle {

            readonly property real size: index === currentIndex ? 8.0 : 4.0

            width: size; height: size

            anchors.centerIn: parent

            color: view.color
        }
    }

    Timer {

        interval: 500; running: true; repeat: true

        onTriggered: {

            parent.currentIndex++

            if (parent.currentIndex === 4) parent.currentIndex = 0
        }
    }

    Component.onCompleted: {

        currentIndex = 0
    }
}