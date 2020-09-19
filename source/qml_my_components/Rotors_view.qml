import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12

Page {

    Rotor {
        id: rotor3_
        anchors.right: rotor2_.left
        anchors.rightMargin: 15
        anchors.verticalCenter: rotor2_.verticalCenter
        indexInBackend: enigma_.active_rotor3
        indexOnView: 3
        symbol: enigma_.rotor3Current
    }

    Rotor {
        id: rotor2_
        anchors.centerIn: parent
        indexInBackend: enigma_.active_rotor2
        indexOnView: 2
        symbol: enigma_.rotor2Current
    }

    Rotor {
        id: rotor1_
        anchors.left: rotor2_.right
        anchors.leftMargin: 15
        anchors.verticalCenter: rotor2_.verticalCenter
        indexInBackend: enigma_.active_rotor1
        indexOnView: 1
        symbol: enigma_.rotor1Current
    }
}
