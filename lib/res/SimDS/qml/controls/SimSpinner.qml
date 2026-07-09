import QtQuick 2.7

import SimDS 1.0

ListView {

    width: SimControl.Size._32px + SimControl.Spacing._04px * 3.0; height: SimControl.Size._32px

    spacing: SimControl.Spacing._04px

    orientation: ListView.Horizontal

    model: 4

    delegate: Item {

        width: 8.0; height: 8.0

        Image {

            anchors.centerIn: parent

            source: index === currentIndex ? "qrc:/SimDS/svg/controls/Loader_8px.svg" : "qrc:/SimDS/svg/controls/Loader_4px.svg"
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