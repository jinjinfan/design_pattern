//
// Created by claudia on 2017/7/9.
//

#ifndef PROTOTYPE_SERIALIZATION_H
#define PROTOTYPE_SERIALIZATION_H

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <ostream>
#include <string>
using namespace std;

struct NewAddress {
    string street;
    string city;
    int suite;

    friend std::ostream &operator<<(std::ostream &os, const NewAddress &address) {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
    friend class boost::serialization::access;
    template <class Ar> void serialize(Ar& ar, const unsigned int version) {
        ar & street;
        ar & city;
        ar & suite;
    }
};

struct NewContact {
    string name;
    NewAddress address;

    friend ostream &operator<<(ostream &os, const NewContact &contact) {
        os << "name: " << contact.name << " address: " << contact.address;
        return os;
    }
    friend class boost::serialization::access;
    template <class Ar> void serialize(Ar& ar, const unsigned int version) {
        ar & name;
        ar & address;
    }
};

#endif //PROTOTYPE_SERIALIZATION_H
