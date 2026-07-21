import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimPage {

    TopPanel {

        id: topPanel

        anchors { left: parent.left; top: parent.top; right: parent.right; margins: SimControl.Margin._12px }
    }

    SimRowScale {

        id: hiOutputVolage

        anchors { left: topPanel.left; top: topPanel.bottom; topMargin: SimControl.Margin._12px }

        scale.min: 0.0; scale.max: 1500.0

        scale.value: engine.device.statusInfo.hiVoltage

        value.text: engine.device.statusInfo.hiVoltage + " В"

        title.text: "Выходное напряжение (в)"
    }

    SimRowScale {

        id: loOutputVolage

        anchors { left: hiOutputVolage.right; top: topPanel.bottom; margins: SimControl.Margin._12px }

        scale.min: 0.0; scale.max: 0.2

        scale.value: engine.device.statusInfo.loVoltage

        value.text: engine.device.statusInfo.loVoltage + " В"

        title.text: "Выходное напряжение (н)"
    }

    InfoPanel {

        anchors { right: topPanel.right; top: topPanel.bottom; bottom: parent.bottom; topMargin: SimControl.Margin._12px; bottomMargin: SimControl.Margin._12px }

        panelIndex: topPanel.buttonIndex
    }


    MetersInfoDialog {

        id: metersInfoDialog

        x: (parent.width - width) / 2.0; y: (parent.height - height) / 2.0

        visible: false
    }

    NetworkInfoDialog {

        id: networkInfoDialog

        x: (parent.width - width) / 2.0; y: (parent.height - height) / 2.0

        visible: false
    }

    VoltageInfoDialog {

        id: hiVoltageInfoDialog

        voltageKind: VoltageInfoDialog.VoltageKind.High

        x: (parent.width - width) / 2.0; y: (parent.height - height) / 2.0

        visible: false
    }

    VoltageInfoDialog {

        id: loVoltageInfoDialog

        voltageKind: VoltageInfoDialog.VoltageKind.Low

        x: (parent.width - width) / 2.0; y: (parent.height - height) / 2.0

        visible: false
    }

    CalibratorInfoDialog {

        id: calibratorInfoDialog

        x: (parent.width - width) / 2.0; y: (parent.height - height) / 2.0

        visible: false
    }
}
