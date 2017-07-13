//
// Created by claudia on 2017/7/12.
//

#ifndef CHAIN_OF_RESPONSIBILITY_CREATURE2_H
#define CHAIN_OF_RESPONSIBILITY_CREATURE2_H

#include <string>
#include <iostream>
using namespace std;

#include <boost/signals2.hpp>
using namespace boost::signals2;

struct Query {
    string creature_name;
    enum Argument { attack, defense } argument;
    int result;

    Query(const string &creature_name, Argument argument, int result) : creature_name(creature_name),
                                                                        argument(argument), result(result) {}
};

struct Game {
    signal<void(Query&)> queries;
};

struct Creature2 {
    Game& game;
    int attack, defense;

public:
    string name;

    Creature2(Game &game, int attack, int defense, const string &name) :
            game(game), attack(attack), defense(defense),name(name) {

    }

    int GetAttack() const {
        Query q{name, Query::Argument::attack, attack};
        game.queries(q);
        return q.result;
    }

    friend ostream &operator<<(ostream &os, const Creature2 &creature2) {
        os <<" name: " << creature2.name << "attack: " << creature2.GetAttack() << " defense: " << creature2.defense;
        return os;
    }
};

class CreatureModifier2 {
    Game& game;
    Creature2& creature;

public:
    CreatureModifier2(Game& game, Creature2 &creature) : game(game), creature(creature) {}

    virtual ~CreatureModifier2() {

    }
};

class DoubleAttackModifier2: public CreatureModifier2 {
    connection conn;
public:
    DoubleAttackModifier2(Game &game, Creature2 &creature): CreatureModifier2(game, creature)
    {
        conn = game.queries.connect([&](Query& q){
            if (q.creature_name == creature.name &&
                    q.argument == Query::Argument::attack)
            {
                q.result *= 2;
            }
        });
    }

    virtual ~DoubleAttackModifier2() {
        conn.disconnect();
    }
};
#endif //CHAIN_OF_RESPONSIBILITY_CREATURE2_H