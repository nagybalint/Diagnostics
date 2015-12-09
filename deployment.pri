unix:!android {
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
            target.path = /opt/$${TARGET}/bin
        }
        export(target.path)
    }
    INSTALLS += target
}

export(INSTALLS)

DISTFILES += \
    $$PWD/imports/QuickPlot/qmldir \
    $$PWD/imports/QuickPlot/Axes.qml \
    $$PWD/imports/QuickPlot/AxisLabels.qml \
    $$PWD/imports/QuickPlot/PlotArea.qml \
    $$PWD/imports/QuickPlot/Tick.qml

