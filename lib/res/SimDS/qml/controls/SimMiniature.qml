import QtGraphicalEffects 1.15
import QtQuick 2.7

import SimDS 1.0

Item {

    signal clicked()

    property alias icon: icon.source

    width: SimControl.Size._20px; height: SimControl.Size._20px

    Image {

        id: icon

        anchors.centerIn: parent
    }

    Glow {

        id: glow

        anchors.fill: icon

        visible: false

        radius: 1.0; samples: 16

        source: icon; color: SimPalette.colors.grey[0]
    }

    MouseArea {

        anchors.fill: parent

        hoverEnabled: true

        onClicked: parent.clicked()

        onEntered: glow.visible = true

        onExited: glow.visible = false
    }
}