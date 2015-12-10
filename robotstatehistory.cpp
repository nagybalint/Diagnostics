#include "robotstatehistory.h"
#include <memory>

RobotStateHistory::RobotStateHistory() : QObject(nullptr), currentState(nullptr)
{

}

void RobotStateHistory::add(RobotState& state)
{  

    qDebug() << "EHOL";
    std::unique_ptr<RobotState> newState = std::make_unique<RobotState>();
    newState->copyFrom(state);
    stateList.append(newState.get());
    currentState = (RobotState*)newState.get(); // This has to be done before moving ownership
    container.push_back(std::move(newState));

    graphSteeringAngle.clear();
    graphFrontLinePos.clear();
    graphCarSpeed.clear();

    int graphStateNumber = stateList.size() < shownStateNumber ? stateList.size() : shownStateNumber;

    auto it = container.end()-graphStateNumber;
    for(; it != container.end(); it++)
    {
        RobotState* currentState = it->get();
        graphSteeringAngle.append(currentState->getSteeringAngle());
        graphFrontLinePos.append(currentState->getFrontSensorAngle());
        graphCarSpeed.append(currentState->getCarSpeed());
    }

    emit this->historyChanged();
}
