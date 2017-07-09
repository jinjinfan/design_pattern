//
// Created by claudia on 2017/7/9.
//

#ifndef FACTORY_HOTDRINK_H
#define FACTORY_HOTDRINK_H

#include <iostream>
#include <memory>
#include <map>
#include <string>
using namespace std;

struct HotDrink {
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink {
    void prepare(int volume) override {
        cout << "Take tea bag, boil water, pour " << volume << "ml water" << endl;
    }
};

struct Coffee : HotDrink {
    void prepare(int volume) override {
        cout << "Grind some beans, boil water, pour " << volume << "ml water" << endl;
    }
};
#endif //FACTORY_HOTDRINK_H
