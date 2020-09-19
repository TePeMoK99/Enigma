import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

RowLayout {
    id: menuBar

    Button {
        Layout.alignment: Qt.AlignCenter
        id: open_comutator_item
        property bool isComutator: false
        text: !isComutator ? "Открыть панель\nкомутатора" :
                             "Закрыть панель\nкомутатора"
        font.family: main_window.fontFamily

        onClicked: {
            isComutator ? swipe_view.decrementCurrentIndex() :
                          swipe_view.incrementCurrentIndex()
            isComutator = !isComutator
        }
    }

    Button {
        Layout.alignment: Qt.AlignCenter
        font.family: main_window.fontFamily
        id: open_rotor_select_item
        property bool isRotorSelection: false
        text: !isRotorSelection ? "Открыть панель\nвыбора роторов" :
                                  "Закрыть панель\nвыбора роторов"

        onClicked: {
            isRotorSelection ? swipe_view_rotors.decrementCurrentIndex() :
                               swipe_view_rotors.incrementCurrentIndex()
            isRotorSelection = !isRotorSelection
        }
    }

    Button {
        Layout.alignment: Qt.AlignCenter
        font.family: main_window.fontFamily
        id: output_select_item
        property bool isOrigin: true
        text: !isOrigin ? "Оригинальный вид" :
                            "Вывод в строку"

        onClicked: {
            isOrigin ? swipe_view_output.incrementCurrentIndex() :
                               swipe_view_output.decrementCurrentIndex()
            isOrigin  = !isOrigin
        }
    }

    Button {
        Layout.alignment: Qt.AlignCenter
        text: "Сбросить настройки\nкомутатора"
        font.family: main_window.fontFamily

        onClicked: {
            enigma_.resetComutator()
            keyboard_comutator.lastColor = "black"
            keyboard_comutator.isClicked = false
            keyboard_comutator.lastClickedSymbol = ""
            keyboard_comutator.isDefault = true
        }
    }

    Button {
        Layout.alignment: Qt.AlignCenter
        id: home_button
        text: "На главный экран"
        font.family: main_window.fontFamily

        onClicked: {
            open_comutator_item.isComutator = false
            open_rotor_select_item.isRotorSelection = false
            output_select_item.isOrigin = true
            swipe_view.decrementCurrentIndex()
            swipe_view_rotors.decrementCurrentIndex()
            swipe_view_output.decrementCurrentIndex()
        }
    }
}
