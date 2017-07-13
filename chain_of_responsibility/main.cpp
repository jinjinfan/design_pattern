#include <iostream>
#include "Creature.h"
#include "Creature2.h"

int main() {
    std::cout << "Pointer chain..." << std::endl;
    Creature goblin{"goblin", 1, 1};
    CreatureModifier root{goblin};
    DoubleAttackModifier r1{goblin};
    DoubleAttackModifier r1_2{goblin};
    IncreaseDefenseModifier r2{goblin};
    NoBonusModifier no{goblin};

    root.add(&r1);
    root.add(&r1_2);
    root.add(&r2);
    root.handle();
    cout << goblin << endl;

    std::cout << "Broker chain..." << std::endl;
    Game game;
    Creature2 goblin2{game, 2, 2, "Strong Goblin"};
    cout << goblin2 << endl;
    {
        DoubleAttackModifier2 dam{game, goblin2};
        cout << goblin2 << endl;
    }
    cout << goblin2 << endl;
    return 0;
}