#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

enum class State {
    OffHook,
    Connecting,
    Connected,
    OnHold
};

inline ostream& operator<<(ostream& os, const State& state) {
    switch(state) {
        case State::OffHook:
            os << "off the hook";
        break;
        case State::Connecting:
            os << "connecting";
        break;
        case State::Connected: 
            os << "connected";
        break;
        case State::OnHold:
            os << "on hold";
        break;
    }
    return os;
}

enum class Trigger {
    CallDialed,
    HungUp,
    CallConnected,
    PlaceOnHold,
    TakenOffHold,
    LeftMessage
};

inline ostream& operator<<(ostream& os, const Trigger& t)
{
  switch (t)
  {
  case Trigger::CallDialed:
    os << "call dialed";
    break;
  case Trigger::HungUp:
    os << "hung up";
    break;
  case Trigger::CallConnected:
    os << "call connected";
    break;
  case Trigger::PlacedOnHold:
    os << "placed on hold";
    break;
  case Trigger::TakenOffHold:
    os << "taken off hold";
    break;
  case Trigger::LeftMessage: 
    os << "left message";
    break;
  default: break;
  }
  return os;
}

void States() {
    map<State, std::vector<pair<Trigger, State>>> rules;
    rules[State::OffHook] = {
        {Trigger::CallDialed, State::Connecting}
    };
    rules[State::Connecting] = {
        {Trigger::HungUp, State::OffHook},
        {Trigger::CallConnected, State::Connected}
    };
    rules[State::Connected] = {
        {Trigger::LeftMessage, State::OffHook},
        {Trigger::HungUp, State::OffHook},
        {Trigger::PlacedOnHold, State::OnHold}
    };

  rules[State::OnHold] = {
        {Trigger::TakenOffHold, State::Connected},
        {Trigger::HungUp, State::OffHook}
  };

  State currentState{State::OffHook};
  while(true) {
    cout << "The phone is currently " << currentState << "\n";
Select_trigger:
    cout << "Select a trigger:" << "\n";
    int i = 0;
    for(auto&  item : rules[currentState]) {
        cout << i++ << "." << item.first << "\n";
    }

    int input;
    cin >> input;
    if (input < 0 || input > rules[currentState].size()-1) {
        cout << "Incorrect option. Please try again. " << "\n";
        goto Select_trigger;
    }
    currentState = rules[currentState][input].second;
  }
}
