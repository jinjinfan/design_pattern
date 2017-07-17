//
// Created by claudia on 2017/7/17.
//

#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H
#include <string>
#include <vector>
#include <iostream>
#include <mutex>
using namespace std;

#include <boost/any.hpp>
using namespace boost;

struct Person;

struct PersonListener {
    virtual ~PersonListener() = default;
    virtual void person_changed(Person&p, const string& property_name, const any new_value) = 0;
};

static mutex mtx;

struct Person {
    explicit Person(int age) : age(age) {}

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        if (this->age == age) return;
        auto old_c_v = get_can_vote();
        this->age = age;
        notify("age", this->age);
        auto new_c_v = get_can_vote();
        if (old_c_v != new_c_v)
            notify("can vote", new_c_v);
    }

    bool get_can_vote() const {
        return age >= 16;
    }

    void subscribe(PersonListener* p) {
        lock_guard<mutex> guard{mtx};
        if (find(begin(listeners), end(listeners), p) == end(listeners))
            listeners.push_back(p);
    }

    void unsubscribe(PersonListener* p) {
        lock_guard<mutex> guard{mtx};
        if (listeners.empty()) return;
        // Multiple identical listeners?
        // erase-remove idiom
        for (auto it = listeners.begin(); it != listeners.end(); ++it)
        {
            if (*it == p)
            {
                *it = nullptr;
            }
        }
    }

private:
    int age;
    vector<PersonListener*> listeners;
    void notify(const string& property_name, const any new_value) {
        lock_guard<mutex> guard{mtx};
        for (const auto& listener : listeners)
            if (listener)
                listener->person_changed(*this, property_name, new_value);

        // Erase and remove
        listeners.erase(
                remove(listeners.begin(), listeners.end(), nullptr),
                listeners.end()
        );
    }
};

struct ConsoleListener :PersonListener {
    void person_changed(Person &p, const string &property_name, const any new_value) override {
        cout << "Person's " << property_name << " has been changed to ";
        if ("age" == property_name) {
            cout << any_cast<int>(new_value);
        }
        else if ("can vote" == property_name) {
            cout << any_cast<bool>(new_value);
        }
        cout << "\n";
    }
};

void observer() {
    Person p{14};
    ConsoleListener cl;
    p.subscribe(&cl);
    p.subscribe(&cl);
    p.setAge(15);
    p.setAge(16);
    p.unsubscribe(&cl);
    p.setAge(17);
}
#endif //OBSERVER_OBSERVER_H
