//
// Created by claudia on 2017/7/17.
//

#ifndef OBSERVER_OBSERVER2_H
#define OBSERVER_OBSERVER2_H
#include <string>
#include <vector>
#include <iostream>
#include <mutex>
using namespace std;

#include <boost/any.hpp>
#include <boost/signals2.hpp>
using namespace boost;

template <typename T>
struct INotifyPropertyChanged {
    virtual ~INotifyPropertyChanged()  = default;
    signals2::signal<void(T&, const string&)> propertyChanged;
};

struct Person2: INotifyPropertyChanged<Person2> {
    Person2(int age) : age(age) {}

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        if (this->age == age)
            return;
        Person2::age = age;
        propertyChanged(*this, "age");
    }

private:
    int age;
};

void observer2() {
    Person2 p{123};
    p.propertyChanged.connect([](Person2&, const string& property_name){
        cout << property_name << " has been changed" << "\n";
    });
    p.setAge(20);
}
#endif //OBSERVER_OBSERVER2_H
