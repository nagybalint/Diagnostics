import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1


Item {
    id: root

    ColumnLayout {
        id: base
        anchors.fill: parent

        Rectangle{
            id: speedRect

            Layout.preferredHeight: base.height/3
            Layout.preferredWidth: base.width
            anchors.top: base.top
            color: "lightgrey"


            DrawGraph {
                id: graphSpeed
                objectName: "speedGraph"
                anchors.fill: parent

                xAxisUnit: "sec"
                yAxisUnit: "m/s"
                graphXAxis: graphSpeedData
            }
        }

        Rectangle {
            id: lineposRect

            Layout.preferredWidth: base.width
            Layout.preferredHeight: base.height / 3
            anchors.top: speedRect.bottom
            color: "lightgrey"

            DrawGraph {
                id: graphPosition
                objectName: "positionGraph"
                anchors.fill: parent

                xAxisUnit: "sec"
                yAxisUnit: "Position"
                graphXAxis: graphPositionData

            }
        }

        Rectangle {
            id: stangleRect

            Layout.preferredWidth: base.width
            Layout.preferredHeight: base.height / 3
            anchors.top: lineposRect.bottom
            color: "lightgrey"

            DrawGraph {
                id: graphOrientation
                objectName: "orientationGraph"
                anchors.fill: parent

                xAxisUnit: "sec"
                yAxisUnit: "rad"
                graphXAxis: graphOrientationData
            }
        }
    }
}

