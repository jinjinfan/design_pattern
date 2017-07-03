#include "BankAccount.h"

int main() {
    auto log = make_shared<ConsoleLogger>();
    BankAccount account{"Primary acocunt", 1000, log};
    account.deposit(2000);
    account.withdraw(2500);
    account.withdraw(1000);

    auto nulllog = make_shared<NullLogger>();
    BankAccount account2{"Primary acocunt", 1000, nulllog};
    account2.deposit(2000);
    account2.withdraw(2500);
    account2.withdraw(1000);

    return 0;
}