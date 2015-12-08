import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Item {

    Component {

        id: monitorDelegate
        Text { text: model.monitorText }

    }

    ColumnLayout {
        id: base
        anchors.fill: parent

        ScrollView {
            id: scrollView1

            anchors.left: parent.left
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: inputRect.top
            anchors.margins: 5


            ListView {

                id: consoleList
                //model: monitorModel
                //delegate: monitorDelegate

                Text {
                    id: name
                    text: qsTr("text")
                }



            }

        }

        Rectangle {
            id: inputRect
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: true
            height: 20
            color: "#ffffff"
            radius: 2
            border.color: "grey"
            border.width: 1

            TextInput {
                font.pixelSize: 10
                anchors.fill: parent
                anchors.margins: 5
                verticalAlignment: TextInput.AlignVCenter
                maximumLength: 65
                cursorVisible: true
            }
        }
    }
}

