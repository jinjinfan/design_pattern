//
// Created by claudia on 2017/7/13.
//

#ifndef COMMAND_ACCOUNT_H
#define COMMAND_ACCOUNT_H

#include <iostream>
#include <vector>
using namespace std;

struct BankAccount {
    int balance = 0;
    int overdraft_limit = -500;

    void deposit(int amount) {
        balance += amount;
        cout << "deposited " << amount <<", balance now " << balance << endl;
    }

    void withdraw(int amount) {
        if (balance - amount >= overdraft_limit) {
            balance -= amount;
            cout << "withdrew " << amount <<", balance now " << balance << endl;
        }
    }
};

struct ICommand {
    virtual ~ICommand() {}
    virtual void call() const = 0;
    virtual void undo() const = 0;
};

struct Command : ICommand{
    BankAccount& account;
    enum Action {deposit, withdraw} action;
    int amount;

    Command(BankAccount &account, Action action, int amount) : account(account), action(action), amount(amount) {

    }
    void call() const override {
        switch (action) {
            case deposit:
                account.deposit(amount);
                break;
            case withdraw:
                account.withdraw(amount);
                break;
            default: break;
        }
    }
    void undo() const override {
        switch (action) {
            case deposit:
                account.withdraw(amount);
                break;
            case withdraw:
                account.deposit(amount);
                break;
            default: break;
        }
    }
};

struct CompositeCommand : vector<Command>, ICommand {
    CompositeCommand(const initializer_list<value_type> &__il) :
            vector<Command>(__il) {}

    void call() const override {
        for(auto& cmd: *this)
            cmd.call();
    }

    void undo() const override {
        for_each(rbegin(), rend(),
        [](const Command& cmd) {cmd.undo();});
    }
};
#endif //COMMAND_ACCOUNT_H
