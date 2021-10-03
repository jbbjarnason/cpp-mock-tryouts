#pragma once

#include <memory>

namespace Smurfs {

class Smurf;

class Crew {
public:
    Crew();
    ~Crew() = default;
    bool goToVillage();
    std::unique_ptr<Smurfs::Smurf> _smurf; // Todo: I would like this to be private
private:
};

}
