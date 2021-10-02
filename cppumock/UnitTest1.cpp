#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "SmurfActions.hpp"

namespace {
#include "Smurf.hpp"

// Reimplement the Smurf class.
// Quite convenient, you are able to override functions as you like.
Smurfs::Smurf::Smurf() {}
void Smurfs::Smurf::goLeft() {
    printf("whoho");
    mock("AMockScope").actualCall("goLeft").onObject(this);
}
// End of reimplementation

// Should #include the cpp which uses Smurf
// For proof of concept the whole implementation is placed here.

class User {
public:
    User() : _smurf(std::make_unique<Smurfs::Smurf>()){};
    ~User() = default;
    void move() {
        _smurf->goLeft();
    }
    std::unique_ptr<Smurfs::Smurf> _smurf; // Todo: I would like this to be private
private:
};

} // End of anonymous namespace


TEST_GROUP(Smurfit)
{
    User* className {nullptr};

    void setup()
    {
        className = new User();
    }
    void teardown()
    {
        delete className;
        mock().clear();
    }
};

TEST(Smurfit, Create)
{
    CHECK(nullptr != className);
    CHECK(true);
    CHECK_EQUAL(1,1);
    LONGS_EQUAL(1,1);
    DOUBLES_EQUAL(1.000, 1.001, .01);
    STRCMP_EQUAL("hello", "hello");
//    FAIL("The prior tests pass, but this one doesn't");
}

TEST(Smurfit, MockingIt)
{
    mock("AMockScope").expectOneCall("goLeft").onObject(className->_smurf.get());
    className->move();
    mock("AMockScope").checkExpectations();
}