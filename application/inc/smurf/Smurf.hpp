#pragma once
#include <string>
#include <memory>

// Public header of the famous smurfing library

namespace Smurfs {
class Action;
class SmurfImpl;

class Smurf {
public:
    Smurf();
    ~Smurf() = default;
    void jump(int height);
    void goLeft();
    void goRight();
    bool isBlue();
    void doAction(Action&);

private:
    std::shared_ptr<SmurfImpl> _impl; // Todo: sizeof error when using unique ptr
};

} // End of namespace Smurfs
