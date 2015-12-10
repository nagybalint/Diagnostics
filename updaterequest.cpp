#include <QObject>
#include <QTimer>
#include <QDebug>
#include "Comm/robotmsghandler.h"
#include "updaterequest.h"

UpdateRequest::UpdateRequest(RobotMsgHandler& handler){
    this->handler = &handler;
    connect(&timer, SIGNAL(timeout()), this, SLOT(tick()));
}

void UpdateRequest::start(float intervalms) {
    period = intervalms;
    timer.start((long) intervalms);
}

void UpdateRequest::stop() {
    timer.stop();
}

void UpdateRequest::tick() {
    handler->sendStatusRequest();
}
