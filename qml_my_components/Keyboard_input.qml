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

        Button_Input {
            symbol: "Q"
        }

        Button_Input {
            symbol: "W"
        }

        Button_Input {
            symbol: "E"
        }

        Button_Input {
            symbol: "R"
        }

        Button_Input {
            symbol: "T"
        }

        Button_Input {
            symbol: "Z"
        }

        Button_Input {
            symbol: "U"
        }

        Button_Input {
            symbol: "I"
        }

        Button_Input {
            symbol: "O"
        }
    }

    RowLayout {
        id: row_2
        width: parent.width - 50
        height: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Button_Input {
            symbol: "A"
        }

        Button_Input {
            symbol: "S"
        }

        Button_Input {
            symbol: "D"
        }

        Button_Input {
            symbol: "F"
        }

        Button_Input {
            symbol: "G"
        }

        Button_Input {
            symbol: "H"
        }

        Button_Input {
            symbol: "J"
        }

        Button_Input {
            symbol: "K"
        }
    }

    RowLayout {
        id: row_3
        width: parent.width
        height: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom

        Button_Input {
            symbol: "P"
        }

        Button_Input {
            symbol: "Y"
        }

        Button_Input {
            symbol: "X"
        }

        Button_Input {
            symbol: "C"
        }

        Button_Input {
            symbol: "V"
        }

        Button_Input {
            symbol: "B"
        }

        Button_Input {
            symbol: "N"
        }

        Button_Input {
            symbol: "M"
        }

        Button_Input {
            symbol: "L"
        }
    }
}
