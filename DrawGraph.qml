import QtQuick 2.4

Canvas {

    id: graphCanvas
    anchors.fill: parent

    width: graphCanvas.width
    height: graphCanvas,height

    property var graphXAxis;
    property var graphYAxis;
    property string xAxisUnit;
    property string yAxisUnit;
    property int ownMargin: 10;

    onPaint: {
        var context = getContext("2d");

        context.fillStyle = "white";
        context.fillRect(0,0,width, height);

        drawXAxis(context);
        drawYAxis(context);
        drawGraph(context, graphXAxis, 0, 5);

    }

    function drawXAxis(context) {
        var xAxisHpos = graphCanvas.height / 2;

        context.beginPath();
        context.moveTo(0, xAxisHpos );
        context.lineTo(graphCanvas.width - ownMargin,xAxisHpos);
        context.stroke();
        context.fillStyle = "black"
        context.font = "20px"
        context.fillText(xAxisUnit, graphCanvas.width - ownMargin - 15,xAxisHpos - 5);
    }

    function drawYAxis(context) {

        context.beginPath();
        context.moveTo(ownMargin, ownMargin);
        context.lineTo(ownMargin, graphCanvas.height - ownMargin);
        context.stroke();
        context.fillText(yAxisUnit, ownMargin + 5, ownMargin + 10);
    }

    function drawGraph(context, data, style, verticalScale) {
        var offset = graphCanvas / 2;

        context.beginPath();
        context.moveTo(ownMargin, offset-data[0]);

        for (var i = 0; i < graphXAxis.length; i++) {
            context.lineTo( (ownMargin + (((graphCanvas.width - ownMargin) / 100) * i))
                           , offset - verticalScale * data[i]);
        }
        context.stroke();
    }
}

