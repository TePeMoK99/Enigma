import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import Enigma 1.0
import "qml_my_components/"

ApplicationWindow {
    id: main_window
    visible: true
    width: 700
    height: 800
    title: "Enigma"
    property string fontFamily: "Oswald"

    header: Menu_Bar {

    }

    Enigma {
        id: enigma_
        onButtonChanged: text_field_out.text += button
    }

    SwipeView {
        id: swipe_view_rotors
        width: parent.width
        height: parent.height / 3
        anchors.horizontalCenter: swipe_view_output.horizontalCenter
        anchors.top: parent.top
        interactive: false

        Rotors_view {

        }

        Rotors_selection {

        }
    }

    SwipeView {
        id: swipe_view_output
        width: parent.width
        height: parent.height / 3
        anchors.centerIn: parent
        interactive: false

        Keyboard_output {
            id: keyboard_output
        }

        Page {

            TextField {
                id: text_field_out
                readOnly: true
                anchors.centerIn: parent
                font.family: main_window.fontFamily
                font.pixelSize: 25
                width: parent.width / 2
            }

            Button {
                anchors.left: text_field_out.right
                anchors.leftMargin: 25
                anchors.verticalCenter: text_field_out.verticalCenter
                text: "Отчистить"
                enabled: text_field_out.length

                onClicked: text_field_out.text = ""
            }
        }
    }


    SwipeView {
        id: swipe_view
        width: parent.width
        height: parent.height / 3
        anchors.horizontalCenter: swipe_view_output.horizontalCenter
        anchors.top: swipe_view_output.bottom
        interactive: false

        Keyboard_input {

        }

        Keyboard_Comutator {
            id: keyboard_comutator
        }
    }
}
