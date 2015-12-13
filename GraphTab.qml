import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1


ColumnLayout {
    id: base
    anchors.margins: 5

    DrawGraph {
        id: graph1
        Layout.preferredHeight: base.height/3
        Layout.preferredWidth: base.width
        anchors.top: base.top

        graphObjectName: "speedGraph"
        xAxisUnit: "sec"
        yAxisUnit: "m/s"
        graphXAxis: graphSpeedData
        lineColor: "green"
        textDef: "0.1"
    }


    DrawGraph {
        id: graph2
        Layout.preferredWidth: base.width
        Layout.preferredHeight: base.height / 3
        anchors.top: graph1.bottom
        anchors.bottom: graph3.top

        graphObjectName: "positionGraph"
        xAxisUnit: "sec"
        yAxisUnit: "m"
        graphXAxis: graphPositionData
        lineColor: "red"
        textDef: "0.1"
    }



    DrawGraph {
        id: graph3
        Layout.preferredWidth: base.width
        Layout.preferredHeight: base.height / 3
        anchors.bottom: parent.bottom


        graphObjectName: "steeringAngleGraph"
        xAxisUnit: "sec"
        yAxisUnit: "rad"
        graphXAxis: graphSteeringAngleData
        lineColor: "blue"
        textDef: "1"
    }

}


