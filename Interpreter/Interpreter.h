//
// Created by claudia on 2017/7/13.
//

#ifndef INTERPRETER_INTERPRETER_H
#define INTERPRETER_INTERPRETER_H
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <memory>
using namespace std;

#include <boost/lexical_cast.hpp>
struct Token {
    enum Type{integer, plus, minus, lparent, rparen} type;
    string text;

    Token(Type type, const string &text) : type(type), text(text) {}

    friend ostream &operator<<(ostream &os, const Token &token) {
        os << "text: " << token.text;
        return os;
    }
};

struct Element {
    virtual ~Element() {

    }
    virtual int eval() const = 0;
};

struct Integer : Element {
    int value;

    Integer(int value) : value(value) {}

    int eval() const override {
        return value;
    }
};

struct BinaryOperation : Element {
    enum Type {addition, substraction} type;
    shared_ptr<Element> lhs, rhs;

    int eval() const override {
        if (type == addition)
            return lhs->eval() + rhs->eval();
        return lhs->eval() - rhs->eval();
    }
};
vector<Token> lex(const string& input) {
    vector<Token> result;
    for (int i = 0; i < input.length(); ++i) {
        switch (input[i]){
            case '+':
                result.push_back(Token{Token::plus, "+"});
                break;
            case '-':
                result.push_back(Token{Token::minus, "-"});
                break;
            case '(':
                result.push_back(Token{Token::lparent, "("});
                break;
            case ')':
                result.push_back(Token{Token::rparen, ")"});
                break;
            default:
                ostringstream buffer;
                buffer << input[i];
                for (int j = i + 1; j < input.size(); ++j) {
                    if(isdigit(input[j])) {
                        buffer << input[j];
                        ++i;
                    } else {
                        result.push_back(Token{Token::integer, buffer.str()});
                        break;
                    }
                }
        }
    }
    return result;
}

shared_ptr<Element> parse(const vector<Token>& tokens) {
    auto result = make_shared<BinaryOperation>();
    bool have_lhs = false;
    for (int i = 0; i < tokens.size(); ++i) {
        auto token = tokens[i];
        switch(token.type){

            case Token::integer: {
                int value = boost::lexical_cast<int>(token.text);
                auto integer = make_shared<Integer>(value);
                if (!have_lhs) {
                    result->lhs = integer;
                    have_lhs = true;
                } else {
                    result->rhs = integer;
                }
            }
                break;
            case Token::plus:
                result->type = BinaryOperation::addition;
                break;
            case Token::minus:
                result->type = BinaryOperation::substraction;
                break;
            case Token::lparent:
            {
                int j = i;
                for (; j < tokens.size(); ++j) {
                    if (tokens[j].type == Token::rparen)
                        break;
                }
                vector<Token> subexpression(&tokens[i+1], &tokens[j]);
                auto element = parse(subexpression);
                if (!have_lhs){
                    result->lhs = element;
                    have_lhs = true;
                }
                else {
                    result->rhs = element;

                }
                i = j;

            }
            break;
            case Token::rparen:
            default:
                break;

        }
    }
    return result;
}

#endif //INTERPRETER_INTERPRETER_H
