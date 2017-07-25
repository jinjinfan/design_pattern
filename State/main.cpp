#include <iostream>
#include "State.h"
#include "BoostState.h"

int main() {
    std::cout << "Boost state!" << std::endl;
    boost_state();
    std::cout << "Hand-made state!" << std::endl;
    States();
    return 0;
}