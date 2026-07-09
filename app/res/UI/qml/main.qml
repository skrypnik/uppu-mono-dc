import QtQuick 2.7
import QtQuick.Window 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import SimDS 1.0

import "pages"

ApplicationWindow
{
    id: mainView

    width: 1920.0; height: 1080.0

    title: engine.config.applicationTitle

    visible: true

    StackLayout {

        id: applicationLayout

        anchors {

            fill: parent
        }

        StartPage {

        }

        PrimaryPage {

        }
    }

    Connections {

        target: engine.network
        function onDeviceConnected() {

            applicationLayout.currentIndex = Page.Index.PrimaryPage
        }
    }

    Component.onCompleted: {

        applicationLayout.currentIndex = Page.Index.StartPage
    }
}
