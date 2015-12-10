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
    minimumWidth: 600
    minimumHeight: 400

    signal sendTextInput(string msg)
    signal keyPressed(int msg)
    signal startCommand()
    signal stopCommand()

    property var frontSensorPos: graphFrontSensorPos
    property var orientationAngle: graphOrientationAngle
    property var batContrV: graphBatContrV
    property var batMotorV: graphBatMotorV


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
            Layout.maximumWidth: 200

            GroupBox {
                id: group

                anchors.fill: parent

                ColumnLayout {

                    anchors.fill: parent

                    Button {
                        id: startBtn
                        anchors.right: parent.right
                        anchors.left: parent.left
                        anchors.top: parent.top
                        text: qsTr("Start")
                        tooltip: "Starts the car"
                        onClicked: startCommand()
                    }

                    Button {
                        id: stopBtn
                        anchors.right: parent.right
                        anchors.left: parent.left
                        anchors.top: startBtn.bottom
                        text: qsTr("Stop")
                        tooltip: "Stops the car"
                        onClicked: stopCommand()
                    }

                    Rectangle {
                        id: statusInfoRect
                        anchors.top: stopBtn.bottom
                        anchors.bottom: orientationRect.top
                        anchors.right: parent.right
                        anchors.left: parent.left
                        anchors.topMargin: 10
                        color: "transparent"

                        Text {
                            id: statusInfo
                            anchors.top: parent.top
                            font.pixelSize: 18
                            text: qsTr("Status info:")
                        }

                        Text {
                            id: batteryText
                            anchors.top: statusInfo.bottom
                            text: qsTr("\nBattery:  3S: " + batContrV + "V   2S: " + batMotorV + "V");
                            color: batterryTextColor
                        }
                    }


                    Rectangle {
                        id: orientationRect
                        anchors.bottom: parent.bottom
                        anchors.right: parent.right
                        anchors.left: parent.left
                        Layout.preferredHeight: parent.width
                        color: "transparent"


                        Canvas {
                            anchors.fill: parent
                            property int circleMargin: 5;

                            onPaint: {
                                var context = getContext("2d");

                                context.beginPath();
                                context.arc(width/2, height/2, (width - (2*circleMargin))/2, 0, 2*Math.PI, false);
                                context.fillStyle = "lightblue";
                                context.fill();

                                context.closePath();
                                context.strokeStyle = "black";
                                context.moveTo(circleMargin, height/2);
                                context.lineTo(width - circleMargin,height/2);
                                context.stroke();
                                context.closePath();
                                context.strokeStyle = "black";
                                context.moveTo(width/2, height - circleMargin);
                                context.lineTo(width/2, circleMargin);
                                context.stroke();
                                context.beginPath();
                                context.arc(width/2, height/2, (width - (2*circleMargin))/2, 0, 2*Math.PI, false);
                                context.clip();
                                context.lineWidth = 2;
                                context.moveTo( width/2  +
                                               (height/2)*Math.tan(orientationAngle) + frontSensorPos*3, 0 );
                                context.lineTo( width/2  -
                                               (height/2)*Math.tan(orientationAngle) + frontSensorPos*3, height);
                                context.strokeStyle = "red";
                                context.stroke();
                            }
                        }
                    }
                }
            }
        }

        Item {

            Layout.minimumWidth: 200

            TabView {
                anchors.fill: parent
                anchors.margins: 5

                Tab {
                    id: graphsTab
                    title: "Graphs"

                    GraphTab {
                        id: mainGraphTab
                        anchors.fill: parent
                    }
                }

                Tab {
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
            }
        }
    }
}
