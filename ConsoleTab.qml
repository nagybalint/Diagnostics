import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1


Item {
    id: root
    anchors.fill: parent

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

        Rectangle {

            id: scrollRect

            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: true
            anchors.top: parent.top
            anchors.bottom: inputRect.top

            color: "lightgray"
            Layout.preferredHeight: 0
            Layout.preferredWidth: 0


            ScrollView {
                id: scrollHistory
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
            anchors.bottom: parent.bottom
            height: 25
            color: "white"
            radius: 1
            Layout.preferredWidth: -1
            Layout.fillHeight: false
            Layout.preferredHeight: -1
            Layout.fillWidth: true
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

