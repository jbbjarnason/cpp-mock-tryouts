#include "SmurfImpl.hpp"

using namespace Smurfs;

void SmurfImpl::jump() {
    _actionAsStr = "jumping";
}

void SmurfImpl::goLeft() {
    _actionAsStr = "left";
}

void SmurfImpl::goRight() {
    _actionAsStr = "right";
}

bool SmurfImpl::isBlue() const {
    return true;
}

void SmurfImpl::doAction(Action& action) {
    action.doAction();
}
