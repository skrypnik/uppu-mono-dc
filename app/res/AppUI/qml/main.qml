import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.0
import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

ApplicationWindow
{
    id: mainView

    width: 1920.0; height: 1080.0

    title: engine.config.applicationTitle

    visible: true

    StackLayout {

        id: layout

        anchors { fill: parent }

        StartPage {

        }

        PrimaryPage {

        }

        ReportPage {

        }
    }

    Connections {

        target: engine.network

        function onDeviceConnected() {

            layout.currentIndex = Pages.Index.PrimaryPage
        }
    }

    Component.onCompleted: {

        layout.currentIndex = Pages.Index.StartPage
    }
}
