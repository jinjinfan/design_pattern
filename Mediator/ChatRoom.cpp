//
// Created by claudia on 2017/7/16.
//

#include "ChatRoom.h"

ChatRoom::PersonReference::PersonReference(vector<Person, allocator<Person>> &people, unsigned int index) : people(
        people), index(index) {}

void ChatRoom::broadcast(const string &origin, const string &message) {
    for(auto& p : people)
        if (p.name != origin)
            p.receive(origin, message);
}

void ChatRoom::message(const string &origin, const string &who, const string &message) {
    auto target = find_if(begin(people), end(people),
    [&](const Person&p) { return p.name == who;});
    if (target != end(people))
        target->receive(origin, message);
}

ChatRoom::PersonReference ChatRoom::join(Person &&p) {
    string join_message = p.name + " joins the chat";
    broadcast("room", join_message);

    p.room = this;
    people.emplace_back(p);
    return {people, static_cast<unsigned int>(people.size())-1};
}

Person* ChatRoom::PersonReference::operator->() const {
    return &people[index];
};