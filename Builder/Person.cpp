//
// Created by claudia on 2017/7/8.
//

#include "Person.h"
#include "PersonBuilder.h"

PersonBuilder Person::create() {
    return PersonBuilder{};
}

ostream &operator<<(ostream &os, const Person &person) {
    os << "street_address: " << person.street_address << " post_code: " << person.post_code << " city: " << person.city
       << " company_name: " << person.company_name << " position: " << person.position << " annual_income: "
       << person.annual_income;
    return os;
}
