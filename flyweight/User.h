//
// Created by claudia on 2017/7/2.
//

#ifndef FLYWEIGHT_USER_H
#define FLYWEIGHT_USER_H
#include <string>
#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>
#include <ostream>

using namespace boost;

typedef uint32_t key;

struct User {
    User(const std::string &first_name, const std::string &last_name) :
            first_name(add(first_name)), last_name(add(last_name)) {}

    const std::string& get_first_name() const {
        return names.left.find(first_name)->second;
    }
    const std::string& get_last_name() const {
        return names.left.find(last_name)->second;
    }

    friend std::ostream &operator<<(std::ostream &os, const User &user){
        os << "first_name: " << user.first_name << " " << user.get_first_name()
           << " last_name: " << user.last_name << " " << user.get_last_name() ;
        return os;
    }
protected:
    static bimap<key, std::string> names;
    static int seed;
    static key add(const std::string& s) {
        auto it = names.right.find(s);
        if ( it == names.right.end()) {
            key id = ++seed;
            names.insert(bimap<key, std::string>::value_type(seed, s));
            return id;
        }
        return it->second;
    }
    key first_name, last_name;
};
int User::seed = 0;
bimap<key, std::string> User::names {};


struct User2 {
    flyweight<std::string> first_name, last_name;

    User2(const std::string &first_name, const std::string &last_name) : first_name(first_name), last_name(last_name) {

    }

    friend std::ostream &operator<<(std::ostream &os, const User2 &user2) {
        os << "first_name: " << user2.first_name << " last_name: " << user2.last_name;
        return os;
    }
};
#endif //FLYWEIGHT_USER_H
