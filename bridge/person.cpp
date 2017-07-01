//
// Created by claudia on 2017/6/30.
//
#include <iostream>
#include "person.h"

struct Person::PersonImpl {
    void greet(Person* p) {
       std::cout<<"hello "<< p->name << std::endl;
    }
};

Person::Person() : impl(new PersonImpl) {}

Person::~Person() {
    delete impl;
}

void Person::greet() {
    impl->greet(this);
}

