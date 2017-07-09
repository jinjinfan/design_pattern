#include <iostream>
#include "Point.h"
#include "DrinkFactory.h"

using namespace std;

int main() {
    std::cout << "Inner factory pattern!" << std::endl;
    std::cout << "NewCartesian!" << std::endl;
    auto p  = Point::Factory.NewCartesian(5, 10);
    cout << p << endl;
    std::cout << "NewPolar!" << std::endl;
    auto pp  = Point::Factory.NewPolar(5, 0);
    cout << pp << endl;

    std::cout << "Abstract factory pattern!" << std::endl;
    DrinkFactory df;
    df.make_drink("tea");
    df.make_drink("coffee");
    DrinkWithVolumeFactory dvf;
    dvf.make_drink("tea");
    return 0;
}