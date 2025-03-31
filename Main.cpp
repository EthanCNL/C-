#include <string> 
#include <iostream>
#include <list>
#include <stdlib.h>
#include <windows.h>
#include <memory>
#include <cstdlib>
#include <vector>

#include "MainLoop.h"
#include "Encounter.h"
#include "item.h"
#include "healthPotion.h"
#include "eqItem.h"
#include "Player.h"
#include "Inventory.h"
#include "Room.h"

using namespace std;
using namespace Loop;
using namespace En;
using namespace IItem;
using namespace Play;
using namespace Inven;
using namespace RoomG;

//General variables
bool isAlive = true;
int monstersKilled;

//Temp variables
string enemyType;
int enemyCount;
bool isPlayerTurn;




//main || Joshua
int main()
{
    static vector<unique_ptr<Room>> rooms;
    int randomRoomNum = rand() & 8;
    rooms.push_back(make_unique<Room>());
    unique_ptr<MainLoop> Loop = make_unique<MainLoop>();
    unique_ptr<Encounter> Combat = make_unique<Encounter>();
    unique_ptr<Player> player = make_unique<Player>();
    unique_ptr<Inventory> inventory = make_unique<Inventory>();
    Loop->SetCombat(false);
    while (isAlive)
    {
        if (!Loop -> ReturnCombat())
        {
            //MainDisplay();
            Loop -> CoreLoop();
        }
        if (Loop->ReturnCombat())
        {
            Combat->Core(Room::enemyNum,Room::roomNumber);
            //Combat();
        }      
    }
    
}