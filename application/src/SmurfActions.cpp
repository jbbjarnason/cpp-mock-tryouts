#include <cstdio>
#include "SmurfActions.hpp"

using namespace Smurfs;

std::string Walking::type() {
    return "Walking";
}

void Walking::doAction() {
    printf("Walking backwards ... beat that\n");
}
