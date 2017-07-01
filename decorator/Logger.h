//
// Created by claudia on 2017/7/1.
//

#ifndef DECORATOR_LOGGER_H
#define DECORATOR_LOGGER_H
using namespace std;
struct Logger {
    function<void()> func;
    string name;

    Logger(const function<void()> &func, const string &name) : func(func), name(name) {

    }
    void operator()() const {
        cout << "Entering function " << name << endl;
        func();
        cout << "Exiting function " << name << endl;
    }
};

template <typename Func>
struct Logger2 {
    Func func;
    string name;

    Logger2(Func &func, const string &name) : func(func), name(name) {

    }
    void operator()() const {
        cout << "Entering function " << name << endl;
        func();
        cout << "Exiting function " << name << endl;
    }
};

template <typename > struct Logger3;

template <typename R, typename... Args>
struct Logger3<R(Args...)> {
    function<R(Args...)> func;
    string name;

    Logger3(const function<R(Args...)> &func, const string &name) : func(func), name(name) {

    }
    R operator()(Args ...args) {
        cout << "Entering function " << name << endl;
        R result = func(args...);
        cout << "Exiting function " << name << endl;
        return result;
    }
};
#endif //DECORATOR_LOGGER_H
