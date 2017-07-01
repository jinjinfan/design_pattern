//
// Created by claudia on 2017/6/30.
//

#ifndef COMPOSITE_GEOMETRY_H
#define COMPOSITE_GEOMETRY_H
#include <iostream>
#include <vector>
struct GraphicObject {
    virtual void draw() = 0;
};

struct Circle : GraphicObject {
    void draw() override {
        std::cout << "Circle " << std::endl;
    }
};

struct Group :GraphicObject {
    std::string name;
    std::vector<GraphicObject*> object;

    Group(const std::string &name) : name(name) {}

    void draw() override {
        std::cout << "Group " << name.c_str() << " contains:" << std::endl;
        for(auto&& o : object)
            o->draw();
    }
};
#endif //COMPOSITE_GEOMETRY_H
