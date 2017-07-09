//
// Created by claudia on 2017/7/9.
//

#ifndef FACTORY_TEAFACTORY_H
#define FACTORY_TEAFACTORY_H

#include "HotDrinkFactory.h"

struct HotDrink;

struct TeaFactory : HotDrinkFactory {
    unique_ptr<HotDrink> make() override {
        return std::make_unique<Tea>();
    }
};

#endif //FACTORY_TEAFACTORY_H
