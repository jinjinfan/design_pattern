//
// Created by claudia on 2017/7/25.
//

#ifndef VISITOR_MULTIPLEDISPATCH_H
#define VISITOR_MULTIPLEDISPATCH_H
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <typeindex>
#include <map>
using namespace std;
struct GameObject;

void collide(GameObject& first, GameObject& second);

struct GameObject {
    virtual ~GameObject() = default;
    virtual type_index type() const = 0;
    virtual void collide(GameObject& other){
        ::collide(*this, other);
    }
};

template <typename T>
struct GameObjectImpl : GameObject {
    type_index type() const override {
        return typeid(T);
    }
};

struct Planet : GameObjectImpl<Planet> {};
struct Asteroid : GameObjectImpl<Asteroid> {};
struct SpaceShip : GameObjectImpl<SpaceShip> {};
struct ArmedSpaceShip : SpaceShip {
    type_index type() const override {
        return typeid(ArmedSpaceShip);
    }
};

void spaceship_planet() { cout << "spaceship lands on planet\n"; }
void asteroid_planet() { cout << "asteroid burns up in atmosphere\n"; }
void asteroid_spaceship() { cout << "asteroid hits and destroys spaceship\n"; }
void asteroid_armed_spaceship() { cout << "spaceship shoots asteroid\n"; }

map<pair<type_index, type_index>, void(*)(void)> outcomes {
        {{typeid(SpaceShip), typeid(Planet)}, spaceship_planet},
        {{typeid(Asteroid), typeid(Planet)}, asteroid_planet},
        {{typeid(Asteroid), typeid(SpaceShip)}, asteroid_spaceship},
        {{typeid(Asteroid), typeid(ArmedSpaceShip)}, asteroid_armed_spaceship}
};

void collide(GameObject& first, GameObject& second) {
    auto it = outcomes.find({first.type(), second.type()});
    if ( it == outcomes.end() ){
        it = outcomes.find({second.type(), first.type()});
        if ( it == outcomes.end() ){
            cout << "Object pass each other harmlessly\n";
            return;
        }
    }
    it->second();
}

void MultipleDispatch() {
    ArmedSpaceShip spaceship;
    Asteroid asteroid;
    Planet planet;

    collide(planet, spaceship);
    collide(planet, asteroid);
    collide(spaceship, asteroid);
    planet.collide(planet);
}
#endif //VISITOR_MULTIPLEDISPATCH_H
