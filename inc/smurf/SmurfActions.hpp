#pragma once

#include <string>

namespace Smurfs {

class Action {
public:
    Action() = default;
    virtual ~Action() = default;
    virtual std::string type() = 0;
    virtual void doAction() = 0;
};

class Walking : public Action {
public:
    Walking() = default;
    ~Walking() override = default;
    std::string type() override;
    void doAction() override;
};

} // End of namespace Smurfs