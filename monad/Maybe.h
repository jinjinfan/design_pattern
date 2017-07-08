//
// Created by claudia on 2017/7/7.
//

#ifndef MONAD_MAYBE_H
#define MONAD_MAYBE_H

#include <string>
#include <iostream>
using namespace std;

template <typename T>
struct Maybe;

template <typename T>
Maybe<T> maybe(T* context) {
    return Maybe<T>(context);
}

template <typename T>
struct Maybe {
    T* context;

    explicit Maybe(T *context) : context(context) {}
    template <typename Func> auto With(Func evaluator) {
        if (context == nullptr) {
            return Maybe<typename remove_pointer<decltype(evaluator(context))>::type>(nullptr);
        }
        else {
            return maybe(evaluator(context));
        }
    }

    template <typename Func> auto Do(Func action) {
        if (context != nullptr) action(context);
        return *this;
    }
};

struct Address {
    string* house_name = nullptr;

};

struct Person {
    Address* address = nullptr;
};

#endif //MONAD_MAYBE_H
