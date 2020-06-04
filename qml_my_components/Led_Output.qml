import QtQuick 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root_led
    property string symbol: "A"
    property bool isActivated: symbol === enigma_.button

    width: 50
    height: width
    Layout.alignment: Qt.AlignVCenter
    radius: 25
    border.width: 1

    color: !isActivated ? "#e4c389" : "#ea990b"
    border.color: "black"

    Text {
        text: parent.symbol
        anchors.centerIn: parent
        font.family: "Consolas"
        font.pixelSize: 25
        color: !parent.isActivated ? "black" : "white"
        font.bold: true
    }

    Timer {
        id: timer_
        interval: 500
        onTriggered: enigma_.button = ""
    }

    onIsActivatedChanged: {
        if (isActivated)
            timer_.start()
    }
}

