#include <iostream>
#include "Account.h"

int main() {
    std::cout << "Single!" << std::endl;
    BankAccount ba;
    vector<Command> commands {
           Command{ba, Command::deposit, 100},
           Command{ba, Command::withdraw, 200}
    };
    cout << ba.balance << endl;
    for (auto& cmd :commands)
        cmd.call();
    cout << ba.balance << endl;
    for_each(commands.rbegin(), commands.rend(),
    [](const Command& cmd){cmd.undo();});
    cout << ba.balance << endl;

    std::cout << "Command list!" << std::endl;
    CompositeCommand compositeCommand {
            Command{ba, Command::deposit, 100},
            Command{ba, Command::withdraw, 200}
    };
    cout << ba.balance << endl;
    compositeCommand.call();
    cout << ba.balance << endl;
    compositeCommand.undo();
    cout << ba.balance << endl;
    return 0;
}