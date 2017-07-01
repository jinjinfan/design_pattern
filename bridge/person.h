//
// Created by claudia on 2017/6/30.
//

#ifndef BRIDGE_PERSON_H
#define BRIDGE_PERSON_H

struct Person {
    std::string name;
    struct PersonImpl;
    PersonImpl* impl;
    void greet();

    Person();

    virtual ~Person();
};

#endif //BRIDGE_PERSON_H
