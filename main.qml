import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

ApplicationWindow {
    id:appwindow
    visible: true
    width: 640
    height: 480
    title: qsTr("git•egylet Diagnostics")
    minimumWidth: 400
    minimumHeight: 400

    signal sendTextInput(string msg)
    signal keyPressed(int msg)

    menuBar : MenuBar {

        Menu {
            title: "File"

            MenuItem {text: "Settings"}
            MenuItem {
                text: "Exit"
                onTriggered: Qt.quit();
            }
        }
    }

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
                anchors.fill: parent
                anchors.margins: 5
                Tab{
                    id: consoleTab
                    title: "Console"

                    ConsoleTab {
                        id: mainConsoleTab
                        anchors.fill: parent
                        historyText: setHistoryText

                        onTextChanged: {
                            sendTextInput(msg);
                        }

                        onUpKeyPressed: {
                            keyPressed(1);
                        }

                        onDownKeyPressed: {
                            keyPressed(2);
                        }
                    }
                }

                Tab {
                    id: graphsTab
                    title: "Graphs"

                    GraphTab {
                        id: mainGraphTab

                        anchors.fill: parent
                    }


                }
            }
        }

    }
}
