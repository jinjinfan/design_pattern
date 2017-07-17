#include <iostream>
#include "Memento.h"

int main() {
    std::cout << "Memento!" << std::endl;

    BankAccount2 ba{100};
    ba.deposit(50); // 150
    ba.deposit(25); // 175
    cout << ba << "\n";

    ba.undo();
    cout << "Undo 1: " << ba << "\n";
    ba.undo();
    cout << "Undo 2: " << ba << "\n";
    ba.redo();
    cout << "Redo 1: " << ba << "\n";
    return 0;
}