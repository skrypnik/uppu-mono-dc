import QtGraphicalEffects 1.15
import QtQuick 2.7

import SimDS 1.0

Item {

    signal clicked()

    /**
     * Miniature icon source alias
     */
    property alias icon: icon.source

    /**
     * Selected property for flat miniature
     */
    property bool selected: false

    width: SimControl.Size._24px; height: SimControl.Size._24px

    Image {

        id: icon

        width: parent.width; height: parent.height

        anchors.centerIn: parent
    }

    Glow {

        id: glow

        anchors.fill: icon

        visible: selected

        radius: parent.selected ? 8.0 : 2.0; samples: 16

        source: icon; color: parent.selected ? SimPalette.colors.blue[500] : SimPalette.colors.grey[0]
    }

    MouseArea {

        anchors.fill: parent

        hoverEnabled: true

        onClicked: parent.clicked()

        onEntered: {

            if (parent.selected) return

            glow.visible = true
        }

        onExited: {

            if (parent.selected) return

            glow.visible = false
        }
    }

    onSelectedChanged: {

        glow.visible = selected
    }
}
