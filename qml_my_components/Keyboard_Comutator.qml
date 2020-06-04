import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12

Page {
    id: root_pane
    property color lastColor: "black"
    property bool isClicked: false
    property string lastClickedSymbol: ""
    property bool isDefault: true
    leftPadding: 15

    RowLayout {
        id: row_1
        width: parent.width
        height: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        z: -1

        Button_Comutator {
            symbol: "Q"
        }

        Button_Comutator {
            symbol: "W"
        }

        Button_Comutator {
            symbol: "E"
        }

        Button_Comutator {
            symbol: "R"
        }

        Button_Comutator {
            symbol: "T"
        }

        Button_Comutator {
            symbol: "Z"
        }

        Button_Comutator {
            symbol: "U"
        }

        Button_Comutator {
            symbol: "I"
        }

        Button_Comutator {
            symbol: "O"
        }
    }

    RowLayout {
        id: row_2
        width: parent.width - 50
        height: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        z: -2

        Button_Comutator {
            symbol: "A"
        }

        Button_Comutator {
            symbol: "S"
        }

        Button_Comutator {
            symbol: "D"
        }

        Button_Comutator {
            symbol: "F"
        }

        Button_Comutator {
            symbol: "G"
        }

        Button_Comutator {
            symbol: "H"
        }

        Button_Comutator {
            symbol: "J"
        }

        Button_Comutator {
            symbol: "K"
        }
    }

    RowLayout {
        id: row_3
        width: parent.width
        height: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        z: -3

        Button_Comutator {
            symbol: "P"
        }

        Button_Comutator {
            symbol: "Y"
        }

        Button_Comutator {
            symbol: "X"
        }

        Button_Comutator {
            symbol: "C"
        }

        Button_Comutator {
            symbol: "V"
        }

        Button_Comutator {
            symbol: "B"
        }

        Button_Comutator {
            symbol: "N"
        }

        Button_Comutator {
            symbol: "M"
        }

        Button_Comutator {
            symbol: "L"
        }
    }
}
