//
// Created by claudia on 2017/7/2.
//

#ifndef NULL_OBJECT_BANKACCOUNT_H
#define NULL_OBJECT_BANKACCOUNT_H
#include <iostream>
#include <string>
#include <memory>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

struct Logger {
    virtual ~Logger() = default;
    virtual void info(const string& s) = 0;
    virtual void warn(const string& s) = 0;
};

struct ConsoleLogger : Logger {
    int count = 0;
    void info(const string &s) override {
        cout << "Info: " << s << endl;
    }

    void warn(const string &s) override {
        cout << "Warn: " << s << endl;
        count++;
    }
};

struct NullLogger : Logger {
    void info(const string &s) override {

    }

    void warn(const string &s) override {

    }
};

struct BankAccount {
    string name;
    int balance = 0;
    std::shared_ptr<Logger> logger;

    BankAccount(const string &name, int balance, std::shared_ptr<Logger>logger) : name(name), balance(balance), logger(logger) {

    }
    void deposit(int amount) {
        balance += amount;
        logger->info("Deposited $" + lexical_cast<string>(amount) + " to " + name
        + ", balance is now $" + lexical_cast<string>(balance));
    }
    void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            logger->info("Withdrew $" + lexical_cast<string>(amount) + " from " + name
                         + ", balance is now $" + lexical_cast<string>(balance));
        }
        else {
            logger->warn("Withdrew $" + lexical_cast<string>(amount) + " from " + name
            + ", but couldn't due to low balance $" + lexical_cast<string>(balance));
        }
    }
};

#endif //NULL_OBJECT_BANKACCOUNT_H
