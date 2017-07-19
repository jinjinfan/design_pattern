#include <iostream>
#include "TextStrategy.h"

int main() {
    std::cout << "Strategy dynamic!" << std::endl;
    test_processor_dynamic();
    std::cout << "Strategy static!" << std::endl;
    test_processor_static();
    return 0;
}