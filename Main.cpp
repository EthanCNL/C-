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
#include "Event.h"

using namespace std;
using namespace Loop;
using namespace En;
using namespace IItem;
using namespace Play;
using namespace Inven;
using namespace RoomG;
using namespace Enem;
using namespace Even;

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

void ResetGame()
{
    Player::playerHp = 100;
    monstersKilled = 0;
    Room::roomNumber = 0;
    isAlive = true;
    system("cls");
}

void LoseScreen()
{
    system("cls");
    cout << "==================================" << endl;
    cout << "            GAME OVER             " << endl;
    cout << "==================================" << endl;
    cout << " You Have DIED!!!!" << endl;
    cout << " Monsters Killed = " << monstersKilled << endl;
    cout << " Rooms Explored = " << Room::roomNumber << endl;

    cout << "Would You Like To Play Again?(Yes/No)";
    string playAgain;
    cin >> playAgain;

    if (playAgain == "yes" || playAgain == "Yes" || playAgain == "y" || playAgain == "Y")
    {
        ResetGame();
    }
    else
    {
        isAlive = false;
        cout << "Thanks For Playing!!" << endl;
        exit(0);
    }
}

void WinScreen()
{
    system("cls");
    cout << "==================================" << endl;
    cout << "            GAME OVER             " << endl;
    cout << "==================================" << endl;
    cout << " You Have Won!!!!" << endl;
    cout << " Monsters Killed = " << monstersKilled << endl;
    cout << " Rooms Explored = " << Room::roomNumber << endl;

    cout << "Would You Like To Play Again?(Yes/No)";
    string playAgain;
    cin >> playAgain;

    if (playAgain == "yes" || playAgain == "Yes" || playAgain == "y" || playAgain == "Y")
    {
        ResetGame();
    }
    else
    {
        isAlive = false;
        cout << "Thanks For Playing!!" << endl;
        exit(0);
    }
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
        int randomEnemyNum = (rand() % 2) + 1;
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
            };
        }
    }
    unique_ptr<MainLoop> Loop = make_unique<MainLoop>();
    unique_ptr<Encounter> Combat = make_unique<Encounter>();
    unique_ptr<Player> player = make_unique<Player>();
    unique_ptr<Inventory> inventory = make_unique<Inventory>();
    unique_ptr<Event> event = make_unique<Event>();
    Loop->SetCombat(false);
    while (isAlive)
    {
        if (!Loop -> ReturnCombat())
        {
            if (Room::roomNumber == rooms[Room::roomNumber]->ReturnPointer().size() - 1 && rooms[Room::roomNumber]->ReturnPointer().empty())
            {
                WinScreen();
            }
            int randomEvent = rand() % 101;
            if (randomEvent >= 0 && randomEvent < 51)
            {
                event -> TriggerEvent();
            }
            if (rooms[Room::roomNumber]->ReturnPointer().size() - 1 == Room::enemyNum)
            {
                Room::roomNumber++;
            }            
            Loop -> CoreLoop(rooms[Room::roomNumber]->GetEnemiesLeft());
        }
        if (Loop->ReturnCombat())
        {
            Combat->Core(rooms[Room::roomNumber] -> ReturnEnemy(Room::enemyNum));           
        } 
        if (Encounter::won)
        {
            Room::enemyNum++;
            monstersKilled++;
            Encounter::won = false;  
        }
        if (Player::playerHp <= 0)
        {
            LoseScreen();
        }
        
    }


    
}







