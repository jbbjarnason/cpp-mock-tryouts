#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

namespace {
#include <Smurf.hpp>

// Reimplement the Smurf class.
Smurfs::Smurf::Smurf() {}
void Smurfs::Smurf::jump(int height) {
    mock("AMockScope").actualCall("jump").onObject(this).withParameter("height", height);
}
void Smurfs::Smurf::goLeft() {
    mock("AMockScope").actualCall("goLeft").onObject(this);
}
void Smurfs::Smurf::goRight() {
    mock("AMockScope").actualCall("goRight").onObject(this);
}
bool Smurfs::Smurf::isBlue() {
    return mock("AMockScope").actualCall("isBlue").onObject(this).returnBoolValueOrDefault(true);
}
void Smurfs::Smurf::doAction(Action& action) {
    mock("AMockScope").actualCall("doAction").onObject(this).withParameterOfType("Action", "action", &action);
}

// Include source files to correctly link to the mocked implementation above
#include "../application/src/Crew.cpp"
#include "../application/src/SmurfActions.cpp"

} // End of anonymous namespace


TEST_GROUP(Smurfit)
{
    Smurfs::Crew* testObj {nullptr};

    void setup()
    {
        testObj = new Smurfs::Crew();
    }
    void teardown()
    {
        delete testObj;
        mock().clear();
    }
};

TEST(Smurfit, Create)
{
    CHECK(nullptr != testObj);
    CHECK(true);
    CHECK_EQUAL(1,1);
    LONGS_EQUAL(1,1);
    DOUBLES_EQUAL(1.000, 1.001, .01);
    STRCMP_EQUAL("hello", "hello");
//    FAIL("The prior tests pass, but this one doesn't");
}

class MyTypeComparator : public MockNamedValueComparator
{
public:
    bool isEqual(const void* object1, const void* object2) override
    {
        printf("comparing ...... \n");
        return true;
    }
    SimpleString valueToString(const void* object) override
    {
        return StringFrom(object);
    }
};

TEST(Smurfit, MockingIt)
{
    mock("AMockScope").expectOneCall("jump").onObject(testObj->_smurf.get()).withParameter("height", 2);
    mock("AMockScope").expectOneCall("goLeft").onObject(testObj->_smurf.get());
    mock("AMockScope").expectOneCall("goRight").onObject(testObj->_smurf.get());
    mock("AMockScope").expectOneCall("isBlue").onObject(testObj->_smurf.get())
        .andReturnValue(false); // Now return value of isBlue is false.

    MyTypeComparator comparator;
    mock().installComparator("Action", comparator);
    auto walk {Walking()};
    mock("AMockScope").expectOneCall("doAction").withParameterOfType("Action", "action", &walk)
        .onObject(testObj->_smurf.get());

    CHECK_FALSE(testObj->goToVillage()); // Go to village returns the isBlue function call, which by default returns true.
    mock("AMockScope").checkExpectations();
    mock().removeAllComparatorsAndCopiers();
}