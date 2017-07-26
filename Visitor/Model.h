//
// Created by claudia on 2017/7/24.
//

#ifndef VISITOR_MODEL_H
#define VISITOR_MODEL_H

#include <string>
#include <vector>
using namespace std;

struct Visitor;

struct Element {
    virtual ~Element() = default;
    virtual void accept(Visitor& v) const = 0;
};

struct TextElement : Element {
    string text;

    explicit TextElement(const string &text) : text(text) {}
};

struct Paragraph : TextElement {
    explicit Paragraph(const string &text) : TextElement(text) {}

    void accept(Visitor &v) const override {
        v.visit(*this);
    }
};

struct ListItem : TextElement {
    explicit ListItem(const string &text) : TextElement(text) {}

    void accept(Visitor &v) const override {
        v.visit(*this);
    }
};

struct List : vector<ListItem>, Element {
    List(const initializer_list<value_type> &__il) : vector<ListItem>(__il) {}

    void accept(Visitor &v) const override {
        v.visit(*this);
    }
};

#endif //VISITOR_MODEL_H
