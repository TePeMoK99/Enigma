import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Rectangle {
    id: root_button

    property string symbol: ""
    property color ringColor: "black"
    property bool isDefault: root_pane.isDefault
    property bool isConnectedNow: false

    height: 60
    width: 50
    Layout.alignment: Qt.AlignVCenter
    color: "transparent"

    Rectangle {
        id: ring_rect
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: 30
        height: width
        color: parent.ringColor
        radius: width / 2

        Rectangle {
            id: dot_tectangle
            anchors.centerIn: parent
            width: 15
            height: width
            radius: width / 2
            color: "white"
        }

        Rectangle {
            id: opacity_rect
            anchors.fill: parent
            radius: width / 2
            opacity: 0.2
            color: "black"
            visible: mouse_area.containsMouse ? true : false
        }

        MouseArea {
            id: mouse_area
            hoverEnabled: true
            anchors.fill: parent

            onPressed: {
                if (root_pane.isClicked === false && root_button.isConnectedNow == false) {
                    root_pane.isDefault = false
                    root_pane.isClicked = true
                    root_pane.lastColor = enigma_.randColor()
                    root_pane.lastClickedSymbol = root_button.symbol
                    root_button.ringColor = root_pane.lastColor
                    root_button.isConnectedNow = true
                }
                else if (root_pane.isClicked === true && root_button.isConnectedNow == false) {
                    root_pane.isClicked = false
                    root_button.ringColor = root_pane.lastColor
                    enigma_.connectSymbols(root_pane.lastClickedSymbol, root_button.symbol)
                    root_button.isConnectedNow = true
                }
            }
        }
    }

    Label {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        text: root_button.symbol
        font.family: "Consolas"
        font.pixelSize: 25
        color: parent.ringColor
        opacity: 1
    }

    onIsDefaultChanged: {
        if (isDefault == true) {
            ringColor = "black"
            isConnectedNow = false
        }
    }
}
