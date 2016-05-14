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
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    model: game.elements
//                    delegate: Text {text: "Element: " + name }

                    property int dragItemIndex: -1

                    delegate: Item {
                        id: delegateItem
                        width: parent.width
                        height: 50

                        Rectangle {
                            id: dragRect
                            width: parent.width
                            height: 50

                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            color: "salmon"
                            border.color: Qt.darker(color)

                            Text {
                                anchors.centerIn: parent
                                text: "Element: " + name
                            }

                            MouseArea {
                                id: mouseArea
                                anchors.fill: parent
                                drag.target: dragRect
                                drag.onActiveChanged: {
                                    if(mouseArea.drag.active)
                                    {
                                        listView1.dragItemIndex = index;
                                    }
                                    dragRect.Drag.drop();
                                }
                            }

                            states: [
                                State {
                                    when: dragRect.Drag.active
                                    ParentChange {
                                        target: dragRect
                                        parent: root
                                    }

                                    AnchorChanges {
                                        target: dragRect
                                        anchors.horizontalCenter: undefined
                                        anchors.verticalCenter: undefined
                                    }
                                }
                            ]

                            Drag.active: mouseArea.drag.active
                            Drag.hotSpot.x: dragRect.width / 2
                            Drag.hotSpot.y: dragRect.height / 2
                        }
                    }

                }
            }

            Button {
                id: button1
                text: qsTr("Add")
                Layout.fillWidth: true
                onClicked: {
                    game.addElement();
                    console.log("Called it");
                }
            }
        }
    }

}
