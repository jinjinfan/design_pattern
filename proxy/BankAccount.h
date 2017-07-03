//
// Created by claudia on 2017/7/2.
//

#ifndef PROXY_BANKACCOUNT_H
#define PROXY_BANKACCOUNT_H

#include <ostream>

struct BankAccount {
    virtual ~BankAccount() = default;
    virtual void deposit(int amount) = 0;
    virtual void withdraw(int amount) = 0;
};

struct CurrentBankAccount : BankAccount {
    explicit CurrentBankAccount(const int balance) :
            balance(balance) {}
    void deposit(int amount) override {
        balance += amount;
    }
    void withdraw(int amount) override {
        if (balance >= amount) {
            balance -= amount;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const CurrentBankAccount &account) {
        os << " balance: " << account.balance;
        return os;
    }

private:
    int balance;
};


#endif //PROXY_BANKACCOUNT_H
