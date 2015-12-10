import QtQuick 2.4

Canvas {

    id: graphCanvas
    anchors.fill: parent

    width: graphCanvas.width
    height: graphCanvas.height

    property var graphXAxis;
    property string xAxisUnit;
    property string yAxisUnit;
    property int ownMargin: 10;
    property var maxValue;
    property var lineColor;

    onPaint: {
        var context = getContext("2d");

        context.fillStyle = "white";
        context.fillRect(0,0,width, height);

        drawXAxis(context);
        drawYAxis(context);
        drawGraph(context, graphXAxis, lineColor, maxValue);

    }

    function drawXAxis(context) {
        var xAxisHpos = graphCanvas.height / 2;

        context.beginPath();
        context.moveTo(0, xAxisHpos );
        context.lineTo(graphCanvas.width - ownMargin,xAxisHpos);
        context.strokeStyle = "grey";
        context.lineWidth = 2;
        context.stroke();
        context.fillStyle = "black";
        context.font = "10px Adelle";
        context.fillText(xAxisUnit, graphCanvas.width - ownMargin - 20,xAxisHpos - 5);
    }

    function drawYAxis(context) {

        context.beginPath();
        context.moveTo(ownMargin, ownMargin);
        context.lineTo(ownMargin, graphCanvas.height - ownMargin);
        context.strokeStyle = "grey";
        context.lineWidth = 2;

        context.stroke();
        context.fillText(yAxisUnit, ownMargin + 5, ownMargin + 10);
    }

    function drawGraph(context, data, style, maxVal) {
        var offset = graphCanvas.height / 2;
        var i;

        context.beginPath();
        context.moveTo(ownMargin, offset);
        context.strokeStyle = style;
        context.lineWidth = 2;

        for (i = 0; i < graphXAxis.length; i++) {
            context.lineTo( (ownMargin + (((graphCanvas.width - ownMargin - 20) / 100) * i))
                           , offset - (graphCanvas.height/(2*maxVal)) * data[i]);
        }
        i = i - 1;
        context.fillText(data[i],ownMargin + 5, ownMargin + 20);
        context.stroke();
    }
}

