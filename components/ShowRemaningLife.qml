import QtQuick 2.0
import assets 1.0

Item {
    anchors {
        top: parent.top
        right: parent.right
        left: parent.left
        rightMargin: 20
        leftMargin: 20
    }
    height: 65
    Rectangle {
        anchors.fill: parent
        color: "transparent"

        Row {
            anchors.fill: parent
            Text {
                height: parent.height
                text: "Kalan Can: "
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
            }
            Repeater {
                model: Presenter.remainnigLife;
                Image {
                    source: "qrc:/images/heart.svg"
                    width: parent.height - 10
                    height: width
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
