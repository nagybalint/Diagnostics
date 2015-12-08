import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

ApplicationWindow {
    id:appwindow
    visible: true
    width: 640
    height: 480
    property alias tab1: tab1
    title: qsTr("git•egylet Diagnostics")


    SplitView {
        anchors.fill: parent
        width: parent.width

        Item {
            id: tmp
            Layout.minimumWidth: 200
        }

        Item {

            Layout.minimumWidth: 200
            TabView {
                id:tabview
                width: parent.width
                anchors.rightMargin: 7
                anchors.leftMargin: 13
                anchors.topMargin: 10
                anchors.bottomMargin: 8
                anchors.fill: parent
                anchors.margins: 10
                Layout.minimumWidth: 200
                Tab{
                    id: tab1
                    title: "Console"

                    ConsoleTab {
                        id: mainConsoleTabe
                        anchors.fill: parent
                    }
                }

                Tab {
                    title: "Graphs"
                }
            }
        }

    }
}
