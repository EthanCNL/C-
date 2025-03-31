#include "Encounter.h"
#include "MainLoop.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "HealthPotion.h"
#include "Room.h"
#include "Enemy.h"
#include "Player.h"
#include <ctime>
#include <cmath>
#include "Inventory.h"

using namespace Enem;
using namespace std;
using namespace Loop;
using namespace IItem;
using namespace RoomG;
using namespace Play;
using namespace Inven;
namespace En
{
    bool Encounter::won;
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
            cin.ignore();
        }
        else
        {
            cout << "You failed to Run!\n";
            cin.ignore();
            cin.ignore();
        }

    }

    //function for enemy to deal damage || Joshua
    void Encounter::EnemyAttack(std::unique_ptr<Enem::Enemy>& enemy)
    {
        cout << "Enemy Turn!\n";
        Player::playerHp -= (enemy -> ReturnATK() + enemy->ReturnATK() - Player::playerArmor);
        cout << "The enemy did " << (enemy->ReturnATK() + enemy->ReturnATK() - Player::playerArmor) << " Damage!\n";
        cin.ignore();
        cin.ignore();
    }

    void Encounter::EnemyRun()
    {
        MainLoop::inCombat = false;
        Encounter::won = true;
        cout << "Enemy Ran!";
        cin.ignore();
        cin.ignore();
    }

    void Encounter::EnemyHeal(std::unique_ptr<Enem::Enemy>& enemy)
    {
        cout << "Enemy Heals Themself!\n";
        int temp = enemy->ReturnHP();
        temp += enemy->ReturnHP() * round(0.2);
        enemy->SetHP(temp);
        cin.ignore();
        cin.ignore();
    }

    // function to damage enemy || Joshua
    void Encounter::Fight(unique_ptr<Enemy>& enemy)
    {
        int temp = enemy -> ReturnHP();
        int temp2 = (temp - (Player::playerAtk + Player::playerWeapon - enemy->ReturnAP()));
        enemy -> SetHP(std::max(0, temp2));
        cout << "\nYou dealt " << Player::playerAtk + Player::playerWeapon - enemy->ReturnAP() << " Damage!\n";
        cin.ignore();
        cin.ignore();
    }


    //combat function || Joshua
    void Encounter::Core(unique_ptr<Enemy>& enemy)
    {
        
        srand(time(0));
        system("cls");
        if (enemy -> ReturnHP() <= 0)
        {
            cout << enemy->ReturnName() << " Defeated! \n";
            Encounter::won = true;
            MainLoop::inCombat = false;     
            return;
        }
        if (Player::playerHp <= 0)
        {
            MainLoop::inCombat = false;
            Encounter::won = false;
        }
        cout << "Your HP: " << Player::playerHp << "\n";
        cout << enemy -> ReturnName() << " HP: " << enemy->ReturnHP() << "\n\n";
        
        if (isPlayerTurn)
        {
            cout << "Your turn!\n\n";
            cout << ("Choose an action: \nFight\tRun\tItem\n");
            cin >> action;
            if (action == "Fight")
            {
                Fight(enemy);
            }
            if (action == "Run")
            {
                Run();
            }
            if (action == "Item")
            {
                if (!Inventory::inventory.empty())
                {
                    HealthPotion potion;
                    potion.Use();
                    Player::playerHp = 100;
                    cin.ignore();
                    cin.ignore();
                }
                
            }
        }
        else
        {
            int randomInt = rand() % 151;
            cout << randomInt;
            if (randomInt >= 0 && randomInt <= 75)
            {
                EnemyAttack(enemy);
            }
            
            if (randomInt > 75 && randomInt <= 100)
            {
                EnemyHeal(enemy);
            }
            
            if (randomInt > 100 && randomInt <= 125)
            {
                cout << "Enemy Blocked!";
                blockModifier = 10;
            }

            if (randomInt > 125 && randomInt <= 150)
            {
                cout << "The Enemy Ran Away!";
                system("cls");
                MainLoop::inCombat = false;

            }
            
        }
        isPlayerTurn = !isPlayerTurn;
    }

    
}
