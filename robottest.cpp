#include "robottest.h"

RobotTest::RobotTest(RobotMsgHandler& handler) : timer() {
    this->handler = & handler;
    timer.setSingleShot(true);
}

void RobotTest::run() {

    static RobotTest::Stage stage = RobotTest::Stage::Start;

    switch (stage) {
    case RobotTest::Stage::Start:
        emit this->robotTestMessage("Self test started -- press next for motor control test");
        stage = RobotTest::Stage::SpeedTest;
        break;
    case RobotTest::Stage::SpeedTest:
        emit this->robotTestMessage("Testing motor control");
        handler->setRobotAttribute(RobotMessage::Type::SetSpeed, 1.0f);
        // Stop car 3 seconds later
        timer.singleShot( 3000, []() {;});
        handler->setRobotAttribute(RobotMessage::Type::SetSpeed, 0.0f);
        emit this->robotTestMessage("Stopping car");
        emit this->robotTestMessage("Press next for servo test");
        stage = RobotTest::Stage::ServoTest;
        break;
    case RobotTest::Stage::ServoTest:
        emit this->robotTestMessage("Testing servo control");
        handler->setRobotAttribute(RobotMessage::Type::SetServo, 3.14f * 15.0f/180.0f);
        timer.singleShot( 3000, []() {;});
        handler->setRobotAttribute(RobotMessage::Type::SetServo, - 3.14f * 15.0f/180.0f);
        timer.singleShot( 3000, []() {;});
        handler->setRobotAttribute(RobotMessage::Type::SetServo, 0.0f);
        emit this->robotTestMessage("Self test finished");
        stage = RobotTest::Stage::Start;
        break;
    }

}

void RobotTest::abort() {

    handler->setRobotAttribute(RobotMessage::Type::SetSpeed, 0.0f);
    handler->setRobotAttribute(RobotMessage::Type::SetServo, 0.0f);
    emit this->robotTestMessage("ABORTing self test");
    emit this->robotTestMessage("Stopping robot");
}
