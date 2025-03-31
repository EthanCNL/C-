#include "Encounter.h"
#include "MainLoop.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "HealthPotion.h"
#include "Room.h"

using namespace std;
using namespace Loop;
using namespace IItem;
using namespace RoomG;
namespace En
{

    bool isPlayerTurn;
    string action;
    int blockModifier;

    Encounter::Encounter()
    {
    }
    Encounter::~Encounter()
    {
    }

    //function to run || Joshua 
    void Encounter::Run()
    {

        int randomNum = rand() % 100;
        if (randomNum <= 50)
        {
            cout << "Ran!\n";
            MainLoop::inCombat = false;
            cin.ignore();
        }
        else
        {
            cout << "You failed to Run!\n";
            cin.ignore();
        }

    }

    //function for enemy to deal damage || Joshua
    void Encounter::EnemyAttack()
    {
        cout << "Enemy Turn!\n";
        //playerHp -= (enemyAtk + enemyWeapon - playerArmor);
        //cout << "The enemy did " << (enemyAtk + enemyWeapon - playerArmor) << " Damage!\n";
        cin.ignore();
    }

    void Encounter::EnemyHeal()
    {
        cout << "Enemy Heals Themself!\n";
        //enemyHp += enemyHP * 0.2f;
        cin.ignore();
    }

    // function to damage enemy || Joshua
    void Encounter::Fight()
    {
        //enemyHp -= (playerAtk + playerWeapon - enemyArmor);
        //cout << "\nYou dealt " << (playerAtk + playerWeapon - enemyArmor - blockModifier) << " Damage!\n";
        cin.ignore();
        cin.ignore();
    }


    //combat function || Joshua
    void Encounter::Core(int enemyNum, int roomNum, std::vector<std::unique_ptr<Room>>& rooms)
    {
        system("cls");
        rooms[roomNum]
        /*if (enemyHp <= 0)
        {
            MainLoop::inCombat = false;
            monstersKilled++;
            decrease # of enemies in room
            return;
        }*/
        /*if (playerHp <= 0)
        {
            MainLoop::inCombat = false;
            //LoseScreen();
        }
        cout << "Your HP: " << playerHp << "\n";
        cout << "Enemy HP: " << enemyHp << "\n\n";
        */
        if (isPlayerTurn)
        {
            cout << "Your turn!\n\n";
            cout << ("Choose an action: \nFight\tRun\tItem\n");
            cin >> action;
            if (action == "Fight")
            {
                Fight();
            }
            if (action == "Run")
            {
                Run();
            }
            if (action == "Item")
            {
                HealthPotion potion;
                potion.Use();
            }
        }
        else
        {
            int modifier = 0;
            // if enemy is *type* + to modifier
            int randomInt = rand() % 101;
            if (randomInt >= 0 || randomInt <= 75)
            {
                EnemyAttack();
            }
            
            if (randomInt > 75 || randomInt <= 100)
            {
                EnemyHeal();
            }
            
            if (randomInt > 100 || randomInt <= 125) //block
            {
                blockModifier = 10;
            }

            if (randomInt > 125 || randomInt <= 150) // Run
            {
                //decrease # of enemies
                cout << "The Enemy Ran Away!";
                MainLoop::inCombat = false;
            }
            
        }
        isPlayerTurn = !isPlayerTurn;
    }
}
