//
// Created by claudia on 2017/7/9.
//

#ifndef FACTORY_DRINKFACTORY_H
#define FACTORY_DRINKFACTORY_H

#include <string>
#include <map>
#include "HotDrinkFactory.h"
#include "CoffeeFactory.h"
#include "TeaFactory.h"

using namespace std;

struct HotDrink;
class DrinkFactory {
    map<string, unique_ptr<HotDrinkFactory>> factoties;

public:
    DrinkFactory() {
        factoties["coffee"] = make_unique<CoffeeFactory>();
        factoties["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string& name) {
        auto drink = factoties[name]->make();
        drink->prepare(200); // Specify volume
        return drink;
    }

};

class DrinkWithVolumeFactory {
    map<string, function<unique_ptr<HotDrink>()>> factories;

public:
    DrinkWithVolumeFactory() {
        factories["tea"] = [] {
            auto tea = make_unique<Tea>();
            tea->prepare(100);
            return tea;
        };
    }
    unique_ptr<HotDrink> make_drink(const string& name) {
        return factories[name]();
    }
};
#endif //FACTORY_DRINKFACTORY_H
