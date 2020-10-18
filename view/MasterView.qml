import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import components 1.0
import assets 1.0

Window {
    visible: true
    width: 413
    height: 480
    title: qsTr("Hangman")
    color: "#f1f1f1"

    Connections {
        target: Mastercontroller.ui_navigationController
        onGoResultPanelView:
            contentFrame.replace("qrc:/view/ResultPanel.qml")
        onGoShowAreaView: {
            contentFrame.replace("qrc:/view/ShowArea.qml")
            console.log("Show Area")
        }
    }

    ShowRemaningLife {
        id: showRemainigLife
    }

    StackView {
        id: contentFrame
        anchors {
            top: showRemainigLife.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            margins: 40
        }

        initialItem: Qt.resolvedUrl("qrc:/view/ShowArea.qml")
        clip: true
    }
}
