#include "SmurfImpl.hpp"

using namespace Smurfs;

void SmurfImpl::jump(int height) {
    printf("Jumping %d high\n", height);
    _actionAsStr = "jumping";
}

void SmurfImpl::goLeft() {
    printf("Going left\n");
    _actionAsStr = "left";
}

void SmurfImpl::goRight() {
    printf("Going right\n");
    _actionAsStr = "right";
}

bool SmurfImpl::isBlue() const {
    printf("Of course I'm blue\n");
    return true;
}

void SmurfImpl::doAction(Action& action) {
    printf("Executing action\n");
    action.doAction();
}
