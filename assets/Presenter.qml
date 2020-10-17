pragma Singleton
import QtQuick 2.0

Item {
    property int remainnigLife: Mastercontroller.ui_gamedatamanagement.remainningLife
    property string textWord: Mastercontroller.ui_gamedatamanagement.currentWord
    property bool visibility: Mastercontroller.visibility
}
