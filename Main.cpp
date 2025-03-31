#include <string> 
#include <iostream>
#include <list>
#include <stdlib.h>
#include <windows.h>
#include <memory>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "MainLoop.h"
#include "Encounter.h"
#include "item.h"
#include "healthPotion.h"
#include "eqItem.h"
#include "Player.h"
#include "Inventory.h"
#include "Room.h"
#include "Enemy.h"

using namespace std;
using namespace Loop;
using namespace En;
using namespace IItem;
using namespace Play;
using namespace Inven;
using namespace RoomG;
using namespace Enem;

//General variables
bool isAlive = true;
int monstersKilled;

//Temp variables
string enemyType;
int enemyCount;
bool isPlayerTurn;
bool Condition;

vector<unique_ptr<Room>> rooms;


void RemoveEnemy(int num)
{
    rooms[num]->RemoveEnemy();
}

//main || Joshua
int main()
{
    Room::roomNumber = 0;
    srand(time(0));
    
    int randomRoomNum = (rand() & 8) + 1;
    for (int i = 0; i < randomRoomNum; i++)
    {
        rooms.push_back(make_unique<Room>());
    }
    for (int i = 0; i < randomRoomNum; i++)
    {
        int randomEnemyNum = (rand() % 3) + 1;
        for (int j = 0; j <= randomEnemyNum; j++)
        {
            int randomEnemyType = rand() % 4;
            if (randomEnemyType == 0)
            {
                rooms[i] -> AddEnemy(make_unique<Slime>());
            }
            if (randomEnemyType == 1)
            {
                rooms[i]->AddEnemy(make_unique<Goblin>());
            }
            if (randomEnemyType == 2)
            {
                rooms[i]->AddEnemy(make_unique<Orc>());
            }
            if (randomEnemyType == 3)
            {
                rooms[i]->AddEnemy(make_unique<Skeleton>());
            }
            rooms[i]->IncrementEnemies();
        }
    }
    unique_ptr<MainLoop> Loop = make_unique<MainLoop>();
    unique_ptr<Encounter> Combat = make_unique<Encounter>();
    unique_ptr<Player> player = make_unique<Player>();
    unique_ptr<Inventory> inventory = make_unique<Inventory>();
    Loop->SetCombat(false);
    while (isAlive)
    {
        if (!Loop -> ReturnCombat())
        {
            Loop -> CoreLoop(rooms[Room::roomNumber]->GetEnemiesLeft());
        }
        if (Loop->ReturnCombat())
        {
            Combat->Core(rooms[Room::roomNumber] -> ReturnEnemy(Room::enemyNum));
            if (Encounter::won)
            {
                cout << "Won!";
                    rooms[Room::roomNumber]->RemoveEnemy();
                    Room::roomNumber++;
                    Encounter::won = false;
            }
        }      
    }
    
}

