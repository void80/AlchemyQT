import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1


Item {
    id: root
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
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    model: game.elements
                    property int dragItemIndex: -1

                    delegate: Item { // TODO: reuse component
                        id: delegateItem
                        width: parent.width
                        height: 50

                        Rectangle {
                            id: dragRect
                            width: 75
                            height: 50

                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            color: "grey"
                            border.color: "darkGrey"

                            Text {
                                anchors.centerIn: parent
                                text: name
                            }

                            MouseArea {
                                id: mouseArea
                                anchors.fill: parent
                                acceptedButtons: Qt.LeftButton | Qt.RightButton
                                onClicked: {
                                    if(mouse.button & Qt.LeftButton)
                                    {
                                        game.selectElement(index);
                                    }
                                    else if(mouse.button & Qt.RightButton)
                                    {
                                        game.combineElement(index);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Button {
                id: button1
                text: qsTr("Add")
                Layout.fillWidth: true
            }
        }

        ColumnLayout {
            id: columnLayout2
            width: 100
            height: 100

            ListView {
                model: game.selectedElement
                delegate: Item { // TODO: reuse component
                    id: selected
                    width: parent.width
                    height: 50

                    Rectangle {
                        width: 75
                        height: 50

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        color: "grey"
                        border.color: "darkGrey"

                        Text {
                            anchors.centerIn: parent
                            text: "Element: " + name
                        }

                        MouseArea {
                            anchors.fill: parent
                        }
                    }
                }
            }
        }
    }
}
