#include "MainLoop.h"
#include <iostream>
#include <string>
#include "Item.h"
#include "Room.h"
using namespace std;
using namespace RoomG;
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
        Room::DisplayRoomInfo();
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
