#include <Crew.hpp>
#include <Smurf.hpp>
#include <SmurfActions.hpp>

using namespace Smurfs;

Crew::Crew() : _smurf(std::make_unique<Smurf>()) {}

bool Crew::goToVillage() {
    _smurf->jump(2);
    _smurf->goLeft();
    _smurf->goRight();
    auto walk { Smurfs::Walking() };
    _smurf->doAction(walk);
    return _smurf->isBlue();
}
