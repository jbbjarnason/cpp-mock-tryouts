#include <Smurf.hpp>
#include "SmurfImpl.hpp"

using namespace Smurfs;

Smurf::Smurf():
_impl(std::make_shared<SmurfImpl>())
{
}

void Smurf::jump() {
    _impl->jump();
}

void Smurf::goLeft() {
    _impl->goLeft();
}

void Smurf::goRight() {
    _impl->goRight();
}

bool Smurf::isBlue() {
    return _impl->isBlue();
}

void Smurf::doAction(Action& action) {
    _impl->doAction(action);
}
