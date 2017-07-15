//
// Created by claudia on 2017/7/15.
//

#ifndef ITERATOR_SINGLELIST_H
#define ITERATOR_SINGLELIST_H
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include <boost/iterator/iterator_facade.hpp>

struct NodeSingle {
    string value;
    NodeSingle* next = nullptr;

    NodeSingle(const string &value) : value(value) {}

    NodeSingle(const string &value, NodeSingle* const parent) : value(value) {
        parent->next = this;
    }
};

struct ListIterator : boost::iterator_facade<ListIterator, NodeSingle, boost::forward_traversal_tag>
{
    NodeSingle* current = nullptr;

    ListIterator() {}

    explicit ListIterator(NodeSingle* const current) : current(current) {}

private:
    friend class boost::iterator_core_access;
    void increment() {current = current->next;}
    bool equal(const ListIterator& other) const {
        return other.current == current;
    }
    NodeSingle& dereference() const {
        return *current;
    }
};

#endif //ITERATOR_SINGLELIST_H
