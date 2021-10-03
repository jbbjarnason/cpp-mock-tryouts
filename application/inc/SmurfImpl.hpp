#pragma once

#include <string>
#include <SmurfActions.hpp>

namespace Smurfs {

class SmurfImpl {
public:
    SmurfImpl() = default;
    ~SmurfImpl() = default;
    void jump(int height);
    void goLeft();
    void goRight();
    bool isBlue() const;
    void doAction(Action&);

private:
    std::string _actionAsStr;
};

}