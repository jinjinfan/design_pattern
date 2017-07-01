//
// Created by claudia on 2017/6/30.
//

#ifndef COMPOSITE_EXPRESSION_H
#define COMPOSITE_EXPRESSION_H

#include <vector>
using namespace std;

struct Expression {
    virtual double eval() = 0;
    virtual void collect(vector<double>& v) = 0;
};

struct Literal : Expression {
    double value;
    explicit Literal(double value) : value(value) {}

    double eval() override {
        return value;
    }

    void collect(vector<double>& v) override {
        v.push_back(value);
    }
};

struct AdditionExpression : Expression {
    shared_ptr<Expression> left, right;

    AdditionExpression(const shared_ptr<Expression> &left, const shared_ptr<Expression> &right) : left(left),
                                                                                                  right(right) {}

    double eval() override {
        return left->eval() + right->eval();
    }

    void collect(vector<double>& v) override {
        left->collect(v);
        right->collect(v);
    }
};
#endif //COMPOSITE_EXPRESSION_H
