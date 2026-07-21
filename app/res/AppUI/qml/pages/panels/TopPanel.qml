import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimFrame {

    property alias buttonIndex: panelButtons.currentIndex

    /**
     * Shows voltage info panels
     */
    signal showInfoPanel(int panel)

    height: SimControl.Size._40px

    SimLabel {

        id: title

        anchors { left: parent.left; verticalCenter: parent.verticalCenter }

        font { pixelSize: SimControl.Size._24px; weight: Font.DemiBold }

        text: "УППУ МОНО DC"
    }

    ListView {

        id: panelButtons

        width: count * SimControl.Size._20px + count * spacing; height: parent.height

        anchors { verticalCenter: parent.verticalCenter; right: closeMiniature.left; rightMargin: SimControl.Margin._12px * 4.0 }

        spacing: SimControl.Spacing._14px

        orientation: ListView.Horizontal

        model: ListModel {

            ListElement { buttonIndex: InfoPanel.Index.VoltageInfo;    buttonIcon: "qrc:/SimDS/svg/controls/Info.svg" }
            ListElement { buttonIndex: InfoPanel.Index.DeviceInfo;     buttonIcon: "qrc:/SimDS/svg/controls/Lightning.svg" }
            ListElement { buttonIndex: InfoPanel.Index.CalibratorInfo; buttonIcon: "qrc:/SimDS/svg/controls/Harmony.svg" }
            ListElement { buttonIndex: InfoPanel.Index.MeterInfo;      buttonIcon: "qrc:/SimDS/svg/controls/Chart.svg" }
        }

        delegate: SimMiniature {

            icon: buttonIcon

            selected: buttonIndex === panelButtons.currentIndex

            onClicked: {

                panelButtons.currentItem.selected = false

                panelButtons.currentIndex = buttonIndex

                panelButtons.currentItem.selected = true
            }
        }
    }

    SimMiniature {

        id: closeMiniature

        anchors { verticalCenter: parent.verticalCenter; right: parent.right }

        icon: "qrc:/SimDS/svg/controls/Close.svg"

        onClicked: {

                /// \todo
        }
    }

}