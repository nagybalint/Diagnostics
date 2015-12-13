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
    minimumHeight: 430

    signal sendTextInput(string msg)
    signal keyPressed(int msg)
    signal startCommand()
    signal stopCommand()
    signal runTestCmd()
    signal abortTestCmd()
    signal setPid(real kp, real ki, real kd)
    signal setSS(string param, string val)

    property var frontSensorPos: graphFrontSensorPos
    property var orientationAngle: graphOrientationAngle
    property var batContrV: graphBatContrV
    property var batMotorV: graphBatMotorV
    property var selfTestMsg: selfTestMessage


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
            Layout.preferredWidth: 200
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

                    GroupBox {
                        id: statusInfo
                        anchors.top: stopBtn.bottom
                        anchors.bottom: canvasGB.top
                        anchors.right: parent.right
                        anchors.left: parent.left
                        Layout.preferredWidth: parent.width
                        title: "STATUS INFO"

                        Text {
                            id: battery3SText
                            anchors.top: parent.top
                            text: qsTr("\nBattery:\n   3S: " + batContrV + "V\n   2S: " + batMotorV + "V");
                            color: batterryTextColor
                        }

                        Text {
                            id: selftestText
                            anchors.top: battery3SText.bottom
                            anchors.margins: 5
                            font.pixelSize: 10
                            Layout.preferredWidth:  parent.width/2
                            text: qsTr("Selftest:")
                        }

                        Button {
                            id:runTestBtn
                            anchors.top: selftestText.bottom
                            anchors.left: parent.left
                            Layout.preferredWidth:  tmp.width/2
                            text: qsTr("Run")
                            onClicked: runTestCmd()

                        }

                        Button {
                            id:abortTestBtn
                            anchors.top: selftestText.bottom
                            anchors.right: parent.right
                            Layout.preferredWidth: tmp.width / 2
                            text: qsTr("Abort")
                            onClicked: abortTestCmd()
                        }

                        Text {
                            id: msgText
                            anchors.top: abortTestBtn.bottom
                            text: qsTr("Message:")
                        }

                        Text {
                            id: testMessage
                            anchors.top: msgText.bottom
                            text: qsTr("" + selfTestMessage);
                        }
                    }

                    GroupBox {
                        id: canvasGB
                        title: "Line Orientation"
                        anchors.bottom: parent.bottom
                        anchors.right: parent.right
                        anchors.left: parent.left

                        Layout.preferredHeight: parent.width

                        Canvas {
                            id: canvasOrientation
                            objectName: "graphOrientation"
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
                                context.moveTo(width/2, height);
                                context.lineTo(width/2, 0);
                                context.stroke();

                                context.beginPath();
                                context.arc(width/2, height/2, (width - (2*circleMargin))/2, 0, 2*Math.PI, false);
                                context.clip();

                                context.beginPath();
                                context.lineWidth = 2;
                                context.moveTo( width/2  +
                                               (height/2)*Math.tan(orientationAngle) + frontSensorPos*300, 0 );
                                context.lineTo( width/2  -
                                               (height/2)*Math.tan(orientationAngle) + frontSensorPos*300, height);
                                context.strokeStyle = "red";
                                context.stroke();
                            }
                        }
                    }
                }
            }
        }

        Item {

            TabView {
                anchors.fill: parent
                anchors.margins: 5

                Tab {
                    id: graphsTab
                    title: "Graphs"
                    anchors.fill: parent

                    GraphTab {
                        id: mainGraphTab
                        anchors.fill: parent
                    }
                }
                Tab {
                    id: configTab
                    title: "Config"
                    anchors.fill: parent
                    anchors.margins: 5


                    ColumnLayout {
                        Layout.preferredHeight: 200
                        Layout.preferredWidth: 200


                        GroupBox {
                            id: pidBox
                            title: "PID"
                            Layout.preferredHeight: 100
                            Layout.preferredWidth: 100
                            Layout.alignment: Qt.AlignTop

                            ColumnLayout{
                                id:configColumn
                                anchors.fill: parent


                                InputText {
                                    id: inKp
                                    title: "Kp:"
                                    Layout.alignment: Qt.AlignTop
                                    Layout.fillWidth: true

                                    onTextChanged: {
                                        setPid(inKp.parameter, inKi.parameter, inKd.parameter);
                                    }
                                }


                                InputText {
                                    id: inKi
                                    title: "Ki:"
                                    anchors.top: inKp.bottom

                                    onTextChanged: setPid(inKp.parameter, inKi.parameter, inKd.parameter);
                                }

                                InputText {
                                    id: inKd
                                    title: "Kd:"
                                    anchors.top: inKi.bottom

                                    onTextChanged: setPid(inKp.parameter, inKi.parameter, inKd.parameter);
                                }

                            }
                        }

                        GroupBox {
                            id: ssBox
                            title: "SS"
                            Layout.preferredHeight: 100
                            Layout.preferredWidth: 100
                            anchors.top: pidBox.bottom

                            ColumnLayout {
                                id: ssColumn
                                anchors.fill: parent

                                InputText {
                                    id: inXi
                                    title: "Xi: "
                                    Layout.alignment: Qt.AlignTop
                                    Layout.fillWidth: true

                                    onTextChanged: setSS(inXi.parameter, inD.parameter)
                                }

                                InputText {
                                    id: inD
                                    title: "D: "
                                    anchors.top: inXi.bottom

                                    onTextChanged: setSS(inXi.parameter, inD.parameter)
                                }
                            }


                        }
                    }
                }

                Tab {
                    id: consoleTab
                    title: "Console"
                    anchors.fill: parent

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
