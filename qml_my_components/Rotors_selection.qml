import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12

Page {

    RowLayout {
        width: parent.width
        anchors.top: parent.top
        anchors.topMargin: 50

        ComboBox {
            id: combo_box3
            currentIndex: enigma_.active_rotor3
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: 75
            model: list_model
        }

        ComboBox {
            id: combo_box2
            currentIndex: enigma_.active_rotor2
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: 75
            model: list_model
        }

        ComboBox {
            id: combo_box1
            currentIndex: enigma_.active_rotor1
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: 75
            model: list_model
        }

        ComboBox {
            id: combo_box4
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: 100
            model: ListModel {

                ListElement {
                    text: "B"
                }

                ListElement {
                    text: "C"
                }
            }
        }

        Button {
            Layout.alignment: Qt.AlignCenter
            text: "Сохранить настройки"
            enabled: combo_box1.currentIndex != combo_box2.currentIndex &&
                     combo_box1.currentIndex != combo_box3.currentIndex &&
                     combo_box2.currentIndex != combo_box3.currentIndex

            onClicked: {
                enigma_.active_rotor1 = combo_box1.currentIndex
                enigma_.active_rotor2 = combo_box2.currentIndex
                enigma_.active_rotor3 = combo_box3.currentIndex
                enigma_.setActiveReflector(combo_box4.currentIndex + 8)                
            }
        }

        ListModel {
            id: list_model

            ListElement {
                text: "I"
            }

            ListElement {
                text: "II"
            }

            ListElement {
                text: "III"
            }

            ListElement {
                text: "IV"
            }

            ListElement {
                text: "V"
            }

            ListElement {
                text: "VI"
            }
            ListElement {
                text: "VII"
            }

            ListElement {
                text: "VIII"
            }
        }
    }
}

