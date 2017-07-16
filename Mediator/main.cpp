#include <iostream>

#include "Person.h"
#include "ChatRoom.h"
#include "Mediator.h"

int main() {
    std::cout << "Chat room!" << std::endl;
    ChatRoom room;
    auto john = room.join(Person{"john"});
    auto jane = room.join(Person{"jane"});
    john->say("hi room");
    jane->say("hi room");

    auto simon = room.join(Person{"simon"});
    simon->say("hi everyone!");

    jane->pm("simon", "glad you could join us, simon");
    std::cout << "Event broker!" << std::endl;
    Game game;
    Player player{"Lily", game};
    Coach coach{game};
    player.score();
    player.score();
    player.score();

    return 0;
}