#include <iostream>
#include "User.h"
#include <string>
#include "Console.h"
#include <boost/lexical_cast.hpp>
using namespace std;

int main() {
    std::cout << "Home-made flyweight" << std::endl;
    User john_doe{"John", "doe"};
    User jane_doe{"Jane", "doe"};
    std::cout << "John " << john_doe << std::endl;
    std::cout << "Jane " << jane_doe << std::endl;

    std::cout << "Boost flyweight" << std::endl;
    User2 john_doe2{"John", "doe"};
    User2 jane_doe2{"Jane", "doe"};
    std::cout << "John " << john_doe2 << std::endl;
    std::cout << "Jane " << jane_doe2 << std::endl;
    std::cout << std::boolalpha << (&jane_doe2.last_name.get() ==
            &john_doe2.last_name.get());

    auto window1 = Console::instance().single("Test", 10, 40);
    window1->Show();
    auto window = Console::instance().multicolumn("Test",
                                                  2, 40, 40);

    for (size_t i = 0; i < 40; i++)
    {
        window->buffers[1]->add_string("This is line " +
                                       boost::lexical_cast<string>(i), i%2 ==0);
    }
    window->Show();
    return 0;
}