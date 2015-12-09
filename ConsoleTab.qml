import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1


Item {
    id: root

    signal textChanged(string msg)
    signal upKeyPressed()
    signal downKeyPressed()

    property var historyText

    Component {

        id: monitorDelegate
        Text { text: modelData }

    }

    ColumnLayout {
        id: base
        anchors.fill: parent
        Layout.minimumWidth: 200

        Rectangle {

            id: scrollRect
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: inputRect.top
            color: "lightgray"


            ScrollView {
                id: scrollView1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                anchors.fill: parent
                anchors.margins: 5

                ListView {

                    id: consoleList
                    model: monitorModel
                    delegate: monitorDelegate

                    onCountChanged: {
                        consoleList.currentIndex = consoleList.count - 1;
                    }
                }
            }

        }

        Rectangle {
            id: inputRect
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            height: 25
            color: "white"
            radius: 1
            Layout.minimumWidth: base.width
            border.color: "grey"
            border.width: 1


            TextInput {
                id: inputText
                activeFocusOnPress: true
                font.pixelSize: 10
                anchors.fill: parent
                anchors.margins: 5
                verticalAlignment: TextInput.AlignVCenter
                maximumLength: 80
                cursorVisible: false
                inputMask: ""

                onActiveFocusChanged: {
                    cursorVisible: true;
                }

                onAccepted: {
                    root.textChanged(inputText.text);
                    inputText.text = "";
                }

                Keys.onUpPressed: {
                    root.upKeyPressed();
                    inputText.text = historyText;
                }
                Keys.onDownPressed: {
                    root.downKeyPressed();
                    inputText.text = historyText;
                }
            }
        }
    }
}

