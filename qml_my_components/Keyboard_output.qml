import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12

Page {
    leftPadding: 15

    RowLayout {
        id: row_1
        width: parent.width
        height: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top

        Led_Output {
            symbol: "Q"
        }

        Led_Output {
            symbol: "W"
        }

        Led_Output {
            symbol: "E"
        }

        Led_Output {
            symbol: "R"
        }

        Led_Output {
            symbol: "T"
        }

        Led_Output {
            symbol: "Z"
        }

        Led_Output {
            symbol: "U"
        }

        Led_Output {
            symbol: "I"
        }

        Led_Output {
            symbol: "O"
        }
    }

    RowLayout {
        id: row_2
        width: parent.width - 50
        height: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Led_Output {
            symbol: "A"
        }

        Led_Output {
            symbol: "S"
        }

        Led_Output {
            symbol: "D"
        }

        Led_Output {
            symbol: "F"
        }

        Led_Output {
            symbol: "G"
        }

        Led_Output {
            symbol: "H"
        }

        Led_Output {
            symbol: "J"
        }

        Led_Output {
            symbol: "K"
        }
    }

    RowLayout {
        id: row_3
        width: parent.width
        height: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom

        Led_Output {
            symbol: "P"
        }

        Led_Output {
            symbol: "Y"
        }

        Led_Output {
            symbol: "X"
        }

        Led_Output {
            symbol: "C"
        }

        Led_Output {
            symbol: "V"
        }

        Led_Output {
            symbol: "B"
        }

        Led_Output {
            symbol: "N"
        }

        Led_Output {
            symbol: "M"
        }

        Led_Output {
            symbol: "L"
        }
    }
}
