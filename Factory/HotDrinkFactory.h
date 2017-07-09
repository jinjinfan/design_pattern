//
// Created by claudia on 2017/7/9.
//

#ifndef FACTORY_HOTDRINKFACTORY_H
#define FACTORY_HOTDRINKFACTORY_H

#include "HotDrink.h"

struct HotDrinkFactory {
    virtual std::unique_ptr<HotDrink> make() = 0;
};
#endif //FACTORY_HOTDRINKFACTORY_H
