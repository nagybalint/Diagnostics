import QtQuick 2.4
import QtQuick.Layouts 1.1


RowLayout {

    property var graphXAxis;
    property string xAxisUnit;
    property string yAxisUnit;
    property var lineColor;
    property var graphObjectName;
    property var textDef

    TextInput {
        id: maxValText
        Layout.preferredWidth: 10
        Layout.preferredHeight: parent.height
        Layout.alignment: Qt.AlignRight
        anchors.right: graphCanvas.left
        anchors.margins: 2
        font.family: "Adelle"
        font.pixelSize: 10
        maximumLength: 4
        text: textDef
        horizontalAlignment: Text.AlignRight
        inputMethodHints: Qt.ImhFormattedNumbersOnly


        onAccepted: {
            graphCanvas.maxValue = parseFloat(maxValText.text);
            cursorVisible: false;
            focus: false;
            graphCanvas.requestPaint();
        }
    }

    TextInput {
        id: minValText
        Layout.maximumWidth: 0
        Layout.alignment: Qt.AlignRight | Qt.AlignBottom
        anchors.right: maxValText.right
        anchors.left: parent.left

        anchors.margins: 0
        font.family: "Adelle"
        font.pixelSize: 10
        maximumLength: 5
        text: "-" + textDef
        horizontalAlignment: Text.AlignRight
        inputMethodHints: Qt.ImhFormattedNumbersOnly

        onAccepted: {
            graphCanvas.minValue = parseFloat(minValText.text);
            cursorVisible: false;
            focus: false;
            graphCanvas.requestPaint();
        }
    }



    Canvas {
        id: graphCanvas
        objectName: graphObjectName

        Layout.preferredWidth: parent.width - maxValText.width - 9
        Layout.preferredHeight: parent.height

        property var context: getContext("2d");
        property var maxValue: parseFloat(maxValText.text);
        property var minValue: parseFloat(minValText.text);


        onPaint: {

            context.fillStyle = "white";
            context.fillRect(0,0,width, height);

            drawXAxis();
            drawYAxis();
            drawGraph(graphXAxis, lineColor, maxValue);

        }

        function drawXAxis() {
            var gridPos = graphCanvas.height / 10;
            var xAxisHpos = (graphCanvas.height) / 2;
            var absPos = xAxisHpos / ((Math.abs(maxValue) + Math.abs(minValue)));
            var textWidth = context.measureText(xAxisUnit);

            context.beginPath();

            for( var i = 1; i < 10; i++){
                context.moveTo(0, gridPos*i);
                context.lineTo(graphCanvas.width,gridPos*i);
            }

            context.strokeStyle = "lightgrey";
            context.lineWidth = 1;
            context.stroke();
            context.beginPath();
            context.moveTo(0, xAxisHpos + (absPos * (maxValue + minValue)));
            context.lineTo(graphCanvas.width , xAxisHpos + (absPos * (maxValue + minValue)));
            context.strokeStyle = "black";
            context.stroke();

            context.fillStyle = "black";
            context.font = "10px Adelle";
            context.textBaseline = "alphabetic"
            //context.fillText(xAxisUnit, graphCanvas.width - textWidth.width, 0);

        }

        function drawYAxis() {

            context.beginPath();
            context.moveTo(0, 2);
            context.lineTo(0, graphCanvas.height - 2);
            context.strokeStyle = "black";
            context.lineWidth = 2;

            context.stroke();
            context.textBaseline = "top"
            //context.fillText(maxValue,5,0);
            context.closePath();
        }

        function drawGraph(data, style, maxVal) {
            var offset = graphCanvas.height / 2;
            var i;

            context.beginPath();
            context.moveTo(0, offset);
            context.strokeStyle = style;
            context.lineWidth = 2;

            for (i = 0; i < graphXAxis.length; i++) {
                context.lineTo( (((graphCanvas.width - 20) / 100) * i)
                               , offset - (graphCanvas.height/(maxVal + Math.abs(minValue))) * data[i]);
            }
            i = i - 1;

            data[i].toFixed(5);
            context.fillText(data[i],5,0);
            context.stroke();
        }
    }
}
