//
// Created by claudia on 2017/7/9.
//

#ifndef PROTOTYPE_CONTACT_H
#define PROTOTYPE_CONTACT_H

#include <string>
#include <ostream>

using namespace std;

struct Address {
    string street;
    string city;
    int suite;

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " suite: " << address.suite;
        return os;
    }
};

struct Contact {
    string name;
    Address* work_address;

    Contact(const string &name, Address *work_address) :
            name(name), work_address(new Address(*work_address)) {}

    virtual ~Contact() {
        delete work_address;
    }

    Contact(const Contact& other): name(other.name),
                                   work_address(new Address(*other.work_address))
    {}

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "name: " << contact.name << " work_address: " << *contact.work_address;
        return os;
    }
};

struct EmployeeFactory {
    static Contact main, aux;
    static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite) {
        return NewEmployee(name, suite, main);
    }
    static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite) {
        return NewEmployee(name, suite, aux);
    }
private:
    static unique_ptr<Contact> NewEmployee(string name, int suite,
                                            Contact& proto) {
        auto result = make_unique<Contact>(proto);
        result->name = name;
        result->work_address->suite  = suite;
        return result;
    }
};

Contact EmployeeFactory::main{"", new Address{"123 East Dr", "London"}};
Contact EmployeeFactory::aux{"", new Address{"123B East Dr", "London"}};
#endif //PROTOTYPE_CONTACT_H
