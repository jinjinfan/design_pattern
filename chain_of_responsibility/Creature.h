//
// Created by claudia on 2017/7/11.
//

#ifndef CHAIN_OF_RESPONSIBILITY_CREATURE_H
#define CHAIN_OF_RESPONSIBILITY_CREATURE_H

#include <string>
#include <iostream>
using namespace std;

struct Creature {
    string name;
    int attack, defense;

    Creature(const string &name, int attack, int defense)
            : name(name), attack(attack), defense(defense) {}

    friend ostream &operator<<(ostream &os, const Creature &creature) {
        os << "name: " << creature.name << " attack: " << creature.attack << " defense: " << creature.defense;
        return os;
    }
};

class CreatureModifier {
    CreatureModifier* next = nullptr;

protected:
    Creature& creature;

public:
    explicit CreatureModifier(Creature &creature) : creature(creature) {}
    virtual ~CreatureModifier() {

    }
    void add(CreatureModifier* cm) {
        if(next) next->add(cm);
        else next = cm;
    }

    virtual void handle() {
        if(next) next->handle();
    }
};

// Double attack
class DoubleAttackModifier : public CreatureModifier {
public:
    DoubleAttackModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        creature.attack *= 2;
        CreatureModifier::handle();
    }
};

// Increase defense by 1 if attack <= 2
class IncreaseDefenseModifier : public CreatureModifier {
public:
    IncreaseDefenseModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        if (creature.attack <= 2) creature.defense++;
        CreatureModifier::handle();
    }
};

// No bonus for creature
class NoBonusModifier : public CreatureModifier {
public:
    NoBonusModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
    }
};
#endif //CHAIN_OF_RESPONSIBILITY_CREATURE_H
