//
// Created by claudia on 2017/7/9.
//

#ifndef FACTORY_COFFEEFACTORY_H
#define FACTORY_COFFEEFACTORY_H

#include "HotDrinkFactory.h"

struct HotDrink;

struct CoffeeFactory : HotDrinkFactory {
    unique_ptr<HotDrink> make() override {
        return std::make_unique<Coffee>();
    }
};
#endif //FACTORY_COFFEEFACTORY_H
