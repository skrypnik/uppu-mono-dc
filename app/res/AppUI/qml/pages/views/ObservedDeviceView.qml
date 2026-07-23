import QtQuick 2.7

import SimDS 1.0

SimFrame {

    id: view

    property QtObject item

    signal selectedChanged()

    width: 320.0

    ListView {

        id: devices

        anchors { fill: parent }

        spacing: SimControl.Spacing._04px

        visible: devices.count

        model: engine.model.deviceModel

        delegate: SimButton {

            width: devices.width

            scheme: SimControl.Scheme.Secondary

            text: item.description + " " + item.address0 + " " + item.serial

            onClicked: {

                view.item = item

                view.selectedChanged()
            }
        }
    }

    SimSpinner {

        anchors.centerIn: parent

        visible: devices.count === 0x00
    }
}
