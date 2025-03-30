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

using namespace std;
using namespace Loop;
using namespace En;
using namespace IItem;

//player variables
int playerArmor;
int playerWeapon;
float playerHp;
float playerAtk;
list<string> playerItems;

//enemy variables
int enemyArmor;
int enemyWeapon;
float enemyHp;
float enemyAtk;

//General variables
bool isAlive = true;
int monstersKilled;
int roomNum;

//Temp variables
string enemyType;
int enemyCount;
bool isPlayerTurn;




//main || Joshua
int main()
{
    
    unique_ptr<MainLoop> Loop = make_unique<MainLoop>();
    unique_ptr<Encounter> Combat = make_unique<Encounter>();
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
            Combat->Core();
            //Combat();
        }      
    }
    
}