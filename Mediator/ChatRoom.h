//
// Created by claudia on 2017/7/16.
//

#ifndef MEDIATOR_CHATROOM_H
#define MEDIATOR_CHATROOM_H


#include "Person.h"

struct ChatRoom {
    vector<Person> people;
    class PersonReference {
        vector<Person>& people;
        unsigned int index;
    public:
        PersonReference(vector<Person, allocator<Person>> &people, unsigned int index);
        Person* operator->() const;
    };

    void broadcast(const string& origin, const string& message);
    PersonReference join(Person&& p);
    void message(const string& origin, const string& who, const string& message);
};


#endif //MEDIATOR_CHATROOM_H
