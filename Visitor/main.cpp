#include <iostream>
#include "Visitor.h"
#include "MultipleDispatch.h"

int main() {
    std::cout << "Double dispatch!" << std::endl;
    visitor();
    std::cout << "Multiple dispatch!" << std::endl;
    MultipleDispatch();
    return 0;
}