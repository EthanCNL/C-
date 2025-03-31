#include "Event.h"
#include "Player.h"
#include "Inventory.h"
#include "Item.h"
#include <memory>
#include <iostream>
#include <list>
#include "HealthPotion.h"
#include <vector>
using namespace Play;
using namespace Inven;
using namespace std;

namespace Even
{ 

    void Event::TriggerEvent() {
        int totalEvents = 3;
        int eventType = rand() % totalEvents;


        switch (eventType) {

        case 0:
            std::cout << "You stepped on a spikey trap! as a result you take 10 damage.\n";
            Player::playerHp -= 10;
            break;  // cases 1 to 3 have std since their variables are from Player.h

        case 1:
            std::cout << "you find a health potion on the floor! it restores 25 hp.\n";
            Inventory::inventory.push_back(make_unique<Item>("Health Potion"));
            break;


        case 2:
            std::cout << "you find an iron chestplate on the floor, it adds 25 armor for you.\n";
            Player::playerArmor += 10;
            break;
        }
    }
}

