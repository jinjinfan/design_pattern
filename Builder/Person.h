//
// Created by claudia on 2017/7/8.
//

#ifndef BUILDER_PERSON_H
#define BUILDER_PERSON_H

#include <string>
#include <ostream>

using namespace std;

class PersonBuilder;

class Person {
    // Address
    string street_address, post_code, city;
    // employment
    string company_name, position;
    int annual_income = 0;
    Person() {}

public:
    static PersonBuilder create();
    Person(Person&& other)
            : street_address{move(other.street_address)},
              post_code{move(other.post_code)},
              city{move(other.city)},
              company_name{move(other.company_name)},
              position{move(other.position)},
              annual_income{other.annual_income}
    {
    }

    Person&operator=(Person&& other) {
        if (this == &other) return *this;
        street_address = std::move(other.street_address);
        post_code = std::move(other.post_code);
        city = std::move(other.city);
        company_name = std::move(other.company_name);
        position = std::move(other.position);
        annual_income = other.annual_income;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Person &person);

    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;
};
#endif //BUILDER_PERSON_H
