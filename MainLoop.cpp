#include "MainLoop.h"
#include <iostream>
#include <string>
#include "Item.h"
using namespace std;
namespace Loop
{
    bool MainLoop::inCombat;
    string action;

    MainLoop::MainLoop()
    {

    } 
    MainLoop::~MainLoop()
    {

    }
	void MainLoop::CoreLoop()
	{
        cout << "Room: " << "\tEnemies: " << "\tAdjacent Rooms: " << "\tChests: " << "\n";
        cout << ("Choose an action:\nFight\tLoot\tExplore\n");
        cin >> MainLoop::action;
        if (MainLoop::action == "Fight")
        {
            MainLoop::inCombat = true;
        }
        system("cls");
	}
    void MainLoop::SetCombat(bool input)
    {
        inCombat = input;
    }
    bool MainLoop::ReturnCombat()
    {
        return MainLoop::inCombat;
    }
}
