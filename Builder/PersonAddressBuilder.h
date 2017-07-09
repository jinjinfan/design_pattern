//
// Created by claudia on 2017/7/8.
//

#ifndef BUILDER_PERSONADDRESSBUILDER_H
#define BUILDER_PERSONADDRESSBUILDER_H

#include <string>
using namespace std;

#include "PersonBuilder.h"

class PersonAddressBuilder : public PersonBuilder {
    typedef PersonAddressBuilder Self;
public:
    PersonAddressBuilder(Person &person);
    Self& at(string street_address) {
        person.street_address = street_address;
        return *this;
    }
    Self& with_postcode(string post_code) {
        person.post_code = post_code;
        return *this;
    }
    Self& in(string city) {
        person.city = city;
        return *this;
    }
};

#endif //BUILDER_PERSONADDRESSBUILDER_H
