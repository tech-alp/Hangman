import QtQuick 2.12
import assets 1.0

Item {
    anchors.fill: parent
    Text {
        id: win
        anchors.centerIn: parent
        font.pixelSize: 20
        text: qsTr("Tebrikler Kazandınız..");
        visible: Presenter.visibility
    }
    Text {
        id: loss
        anchors.centerIn: parent
        font.pixelSize: 20
        text: qsTr("Üzgünüm Tekrar Deneyiniz?..");
        visible: !(Presenter.visibility)
    }
    Rectangle {
        id: playBtn
        anchors {
            left: parent.left
            bottom: parent.bottom
            bottomMargin: 20
            leftMargin: 20
        }
        width: 120
        height: 40
        radius: 5
        color: "#5555ff"
        //visible: Presenter.visibility  //From Presenter
        Text {
            anchors.fill: parent
            text: "Tekrar Oyna"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
        }
        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                console.log("Giriş Yap")
                Mastercontroller.onPlayAgainClick();
            }
        }
    }


    Rectangle {
        id: closeBtn
        anchors {
            right: parent.right
            bottom: parent.bottom
            bottomMargin: 20
            rightMargin: 20
        }
        width: 120
        height: 40
        radius: 5
        color: "#5555ff"
        //visible: Presenter.visibility  //From Presenter
        Text {
            anchors.fill: parent
            text: "Çıkış Yap"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
        }
        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                console.log("Çıkş Yapıldı..")
                Qt.quit();
            }
        }
    }
}
