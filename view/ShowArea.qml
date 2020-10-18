import QtQuick 2.12
import QtGraphicalEffects 1.0
import assets 1.0

Item {
    id: root
    Rectangle {
        id: mainArea
        color: "#5555ff"
        anchors.fill: parent
        anchors.margins: 5
        radius: 10
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#e6e9f0"
            }

            GradientStop {
                position: 1
                color: "#eef1f5"
            }
        }
        layer.enabled: true
        layer.effect: DropShadow {
            transparentBorder: true
        }
        Text {
            id: textArea
            anchors {
                top: parent.top
                right: parent.right
                left: parent.left
                topMargin: 50
                rightMargin: 10
                leftMargin: 10
            }
            height: 30
            text: Presenter.textWord
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextInput {
            id: textInput
            anchors {
                top: textArea.bottom
                horizontalCenter: parent.horizontalCenter
                topMargin: 20
            }
            width: 30
            height: 30
            text: "?"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
            focus: false
            Keys.onEnterPressed: {
                    console.log("Entered : ",textInput.text)
            }

            Rectangle {
                anchors {
                    bottom: parent.bottom
                    right: parent.right
                    left: parent.left
                    bottomMargin: 5
                }
                height: 2
                color: "dark grey"
            }

            Rectangle {
                id: okBtn
                anchors {
                    top: textInput.bottom
                    horizontalCenter: parent.horizontalCenter
                    topMargin: 50
                }
                width: 80
                height: 40
                radius: 5
                color: "#ff5500"
                //visible: !(Presenter.visibility)
                Text {
                    anchors.fill: parent
                    text: "Dene"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 24
                }
                MouseArea {
                    id: mosuearea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        Mastercontroller.onTryClick(textInput.text);
                        console.log("remain = ",Presenter.remainnigLife)
                    }
                }
            }
        }
    }
}


