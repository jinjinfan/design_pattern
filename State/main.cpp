#include <iostream>
#include "State.h"
#include "BoostState.h"

int main() {
    std::cout << "Hand-made state!" << std::endl;
    States();
    std::cout << "Boost state!" << std::endl;
    boost_state();
    return 0;
}