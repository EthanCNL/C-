

#include "Event.h"
//#include "Player.h"
//#include "Enemy.h"
#include <memory>
#include <iostream>
#include <list>

void Event::TriggerEvent(Room& currentRoom, float& playerHp, float& playerArmor,
    std::list<std::string>& playerItems) {
    int totalEvents = 4;
    int eventType = rand() % totalEvents;

    switch (eventType) {
    case 0:
        std::cout << "Watch out! An enemy appeared!\n";
        currentRoom.AddEnemy(make_unique<Enemy>(monsterList[rand() % monsterList.size()])); //uses make_unique as asked for in question 6 as well as polymorphism, this case has std since <enemy> struct  is from Enemy.h 
        break;

    case 1:
        std::cout << "You stepped on a spikey trap! as a result you take 10 damage.\n";
        playerHp -= 10;
        break;  // cases 1 to 3 have std since their variables are from Player.h

    case 2:
        std::cout << "you find a health potion on the floor! it restores 25 hp.\n";
        playerItems.push_back("Health Potion");
        break;


    case 3:
        std::cout << "you find an iron chestplate on the floor, it adds 25 armor for you.\n";
        playerArmor += 25;
        break;
    }
}
