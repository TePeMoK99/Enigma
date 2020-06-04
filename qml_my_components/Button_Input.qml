import QtQuick 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root_button
    property string symbol: "A"
    width: 50
    height: width
    radius: 25
    border.width: 3
    color: !mouse_area.pressed ? "black" : "#2d2c2c"
    border.color: !mouse_area.pressed ? "#e69200" : "#e4d18c"
    Layout.alignment: Qt.AlignVCenter

    Text {
        text: parent.symbol
        anchors.centerIn: parent
        font.family: "Consolas"
        font.pixelSize: 25
        color: "white"
        font.bold: true
    }

    MouseArea {
        id: mouse_area
        anchors.fill: parent
        hoverEnabled: true
        onClicked: enigma_.press(parent.symbol)
    }
}
