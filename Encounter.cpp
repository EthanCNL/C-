#include "Encounter.h"
#include "MainLoop.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "HealthPotion.h"
using namespace std;
using namespace Loop;
using namespace IItem;
namespace En
{
    bool isPlayerTurn;
    string action;

    Encounter::Encounter()
    {
        cout << "Battle Start!";
    }
    Encounter::~Encounter()
    {
        cout << "Battle End";
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
        //cout << "\nYou dealt " << (playerAtk + playerWeapon - enemyArmor) << " Damage!\n";
        cin.ignore();
        cin.ignore();
    }


    //combat function || Joshua
    void Encounter::Core()
    {
        system("cls");
        /*if (enemyHp <= 0)
        {
            MainLoop::inCombat = false;
            monstersKilled++;
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
            int randomInt = rand() % 2;
            if (randomInt == 0);
            EnemyAttack();
            if (randomInt == 1);
            EnemyHeal();
        }
        isPlayerTurn = !isPlayerTurn;
    }
}
