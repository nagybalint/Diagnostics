import QtQuick 2.0
import QtQuick.Layouts 1.1

RowLayout {
    id: root
    property var title;
    property var parameter:parseFloat(input.text);
    signal textChanged();



    Text {
        id: titleText
        Layout.alignment: Qt.AlignTop
        text: qsTr(title)
    }

    TextInput {
        id:input
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignTop
        text: "0"

        onAccepted: {
            root.textChanged();
        }
    }
}

