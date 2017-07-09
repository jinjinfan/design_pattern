//
// Created by claudia on 2017/7/8.
//

#ifndef BUILDER_PERSONBUILDER_H
#define BUILDER_PERSONBUILDER_H

#include "Person.h"
class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilder {
    Person p;
protected:
    Person& person;
    PersonBuilder(Person &person): person(person) {

    }
public:
    PersonBuilder():person(p) {}
    operator Person() {
        return move(person);
    }
    PersonAddressBuilder lives();
    PersonJobBuilder works();
};
#endif //BUILDER_PERSONBUILDER_H
