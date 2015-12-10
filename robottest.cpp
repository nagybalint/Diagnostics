#include "robottest.h"

RobotTest::RobotTest(RobotMsgHandler& handler) : timer() {
    this->handler = & handler;
    timer.setSingleShot(true);
}

void RobotTest::run() {

    static RobotTest::Stage stage = RobotTest::Stage::Start;

    switch (stage) {
    case RobotTest::Stage::Start:
        emit this->robotTestMessage("Next - motertest");
        stage = RobotTest::Stage::SpeedTest;
        break;
    case RobotTest::Stage::SpeedTest:
        handler->setRobotAttribute(RobotMessage::Type::SetSpeed, 1.0f);
        // Stop car 3 seconds later
        timer.singleShot( 3000, []() {;});
        handler->setRobotAttribute(RobotMessage::Type::SetSpeed, 0.0f);
        emit this->robotTestMessage("Motortest over | Next - servotest");
        stage = RobotTest::Stage::ServoTest;
        break;
    case RobotTest::Stage::ServoTest:
        handler->setRobotAttribute(RobotMessage::Type::SetServo, 3.14f * 15.0f/180.0f);
        timer.singleShot( 3000, []() {;});
        handler->setRobotAttribute(RobotMessage::Type::SetServo, - 3.14f * 15.0f/180.0f);
        timer.singleShot( 3000, []() {;});
        handler->setRobotAttribute(RobotMessage::Type::SetServo, 0.0f);
        emit this->robotTestMessage("Self test over");
        stage = RobotTest::Stage::Start;
        break;
    }

}

void RobotTest::abort() {

    handler->setRobotAttribute(RobotMessage::Type::SetSpeed, 0.0f);
    handler->setRobotAttribute(RobotMessage::Type::SetServo, 0.0f);
    emit this->robotTestMessage("ABORT - stopping robot");
}
