import QtQuick.Layouts 1.15
import QtQuick 2.7

import AppUI 1.0
import SimDS 1.0

SimFrame {

    /**
     * Current info index property alias
     */
    property alias panelIndex: infoPanelLayout.currentIndex

    enum Index {

        VoltageInfo    = 0x00,
        DeviceInfo     = 0x01,
        CalibratorInfo = 0x02,
        MeterInfo      = 0x03
    }

    width: 480.0 + SimControl.Padding._14px * 4.0

    StackLayout {

        id: infoPanelLayout

        anchors { fill: parent }

        Column {

            SimPanel {

                controls: SimPanel.Controls.Edit

                title: "Информация об устройстве"

                Column {

                    DeviceInfoView {

                    }
                }

                onEdit: {

                    networkInfoDialog.visible = true
                }
            }

            SimPanel {

                title: "Статус устройства"

                Column {

                    StatusInfoView {

                    }
                }
            }
        }

        Column {

            SimPanel {

                controls: SimPanel.Controls.Edit

                title: "Параметры высокого напряжения"

                Column {

                    HiVoltageInfoView {

                    }
                }

                onEdit: {

                    hiVoltageInfoDialog.visible = true
                }
            }

            SimPanel {

                controls: SimPanel.Controls.Edit

                title: "Параметры низкого напряжения"

                Column {

                    LoVoltageInfoView {

                    }
                }

                onEdit: {

                    loVoltageInfoDialog.visible = true
                }
            }
        }

        Column {

            SimPanel {

                title: "Параметры калибратора"

                Column {

                    CalibratorReadingsView {

                    }
                }
            }
        }

        Column {

            SimPanel {

                controls: SimPanel.Controls.Edit

                title: "Параметры счетчиков"

                Column {

                    MetersInfoView {

                    }
                }

                onEdit: {

                    metersInfoDialog.visible = true
                }
            }
        }
    }
}