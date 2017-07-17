//
// Created by claudia on 2017/7/16.
//

#ifndef MEMENTO_MEMENTO_H
#define MEMENTO_MEMENTO_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Memento {
    int balance;

public:
    Memento(int balance) : balance(balance) {}
    friend class BankAccount;
    friend class BankAccount2;
};

class BankAccount {
    int balance = 0;
public:
    explicit BankAccount(int balance) : balance(balance) {}
    void restore(const Memento& m) {
        balance = m.balance;
    }
    Memento deposit(int amount) {
        balance += amount;
        return {balance};
    }

    friend ostream &operator<<(ostream &os, const BankAccount &account) {
        os << "balance: " << account.balance;
        return os;
    }
};


class BankAccount2 {
    int balance = 0;
    vector<shared_ptr<Memento>> changes;
    int current;
public:
    explicit BankAccount2(int balance) : balance(balance) {
        changes.emplace_back(make_shared<Memento>(balance));
        current = 0;
    }
    void restore(const shared_ptr<Memento>& m) {
        if (m) {
            balance = m->balance;
            changes.push_back(m);
            current = static_cast<int>(changes.size())-1;
        }
    }
    shared_ptr<Memento> deposit(int amount) {
        balance += amount;
        auto m = make_shared<Memento>(balance);
        changes.push_back(m);
        ++current;
        return m;
    }

    shared_ptr<Memento> undo() {
        if (current > 0) {
            --current;
            auto m = changes[current];
            balance = m->balance;
            return m;
        }
        return {};
    }

    shared_ptr<Memento> redo() {
        if (current < changes.size()-1) {
            ++current;
            auto m = changes[current];
            balance = m->balance;
            return m;
        }
        return {};
    }

    friend ostream &operator<<(ostream &os, const BankAccount2 &account) {
        os << "balance: " << account.balance;
        return os;
    }
};
#endif //MEMENTO_MEMENTO_H
