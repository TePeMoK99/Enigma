import QtQuick 2.0

Image {
    property string symbol: ""
    property int indexOnView: 0
    property int indexInBackend: 0

    height: 200
    width: 50
    source: "qrc:/images/rotor.png"

    Text {
        id: next_symbol
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 15
        font.pixelSize: mouse_area1.containsMouse ? 40 : 35
        font.family: "Consolas"
        text: enigma_.intToChar(parent.symbol.charCodeAt(0) + 1)

        MouseArea {
            id: mouse_area1
            anchors.fill: parent
            onClicked: enigma_.moveOneRotor(indexOnView, indexInBackend, 1)
            hoverEnabled: true
        }
    }

    Text {
        id: cur_symbol
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 40
        font.family: "Consolas"
        text: parent.symbol
    }

    Text {
        id: prev_symbol
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        font.pixelSize: mouse_area2.containsMouse ? 40 : 35
        font.family: "Consolas"
        text: enigma_.intToChar(parent.symbol.charCodeAt(0) - 1)

        MouseArea {
            id: mouse_area2
            anchors.fill: parent
            onClicked: enigma_.moveOneRotor(indexOnView, indexInBackend, -1)
            hoverEnabled: true
        }
    }
}

