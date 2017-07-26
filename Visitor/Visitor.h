//
// Created by claudia on 2017/7/24.
//

#ifndef VISITOR_VISITOR_H
#define VISITOR_VISITOR_H

#include <string>

struct List;
struct ListItem;
struct Paragraph;

struct Visitor {
    virtual ~Visitor() = default;
    virtual void visit(const Paragraph& p) = 0;
    virtual void visit(const ListItem& p) = 0;
    virtual void visit(const List& p) = 0;
    virtual std::string str() const = 0;
};

void visitor();
#endif //VISITOR_VISITOR_H
