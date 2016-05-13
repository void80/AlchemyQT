import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480
    property alias listView1: listView1
    property alias chkShowTerminal: chkShowTerminal


    RowLayout {
        id: rowLayout1
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Rectangle {
            id: rectangle1
            width: 200
            height: 200
            color: "#ffffff"
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        ColumnLayout {
            id: columnLayout1
            width: 100
            height: 100
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop

            CheckBox {
                id: chkShowTerminal
                text: qsTr("Zeige Terminale")
                checked: true
            }

            CheckBox {
                id: chkShowFinished
                width: 150
                height: 17
                text: qsTr("nicht kobinierbar")
                checked: true
            }

            CheckBox {
                id: chkShowCurrentlyFinished
                width: 150
                text: qsTr("jetzt nicht kombinierbar")
                clip: false
                checked: true
            }

            ScrollView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                ListView {
                    id: listView1
                    x: 0
                    y: 0
                    width: 110
                    height: 160
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    model: game.elements()
                    delegate: Text {text: "Element: " + name }
//                    model: ListModel {
//                        ListElement {
//                            name: "Grey"
//                            colorCode: "grey"
//                        }

//                        ListElement {
//                            name: "Red"
//                            colorCode: "red"
//                        }

//                        ListElement {
//                            name: "Blue"
//                            colorCode: "blue"
//                        }

//                        ListElement {
//                            name: "Green"
//                            colorCode: "green"
//                        }
//                    }
//                    delegate: Item {
//                        x: 5
//                        width: 80
//                        height: 40
//                        Row {
//                            id: row1
//                            Rectangle {
//                                width: 40
//                                height: 40
//                                color: colorCode
//                            }

//                            Text {
//                                text: name
//                                font.bold: true
//                                anchors.verticalCenter: parent.verticalCenter
//                            }
//                            spacing: 10
                    //                        }
                    //                    }
                }
            }

            Button {
                id: button1
                text: qsTr("Add")
                Layout.fillWidth: true
            }
        }
    }

}
