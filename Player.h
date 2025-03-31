#pragma once
#include <list>
#include <string>
#include "Item.h"
#include <vector>
#include <memory>

using namespace std;
using namespace IItem;

namespace Play
{
	class Player
	{
	public:
		static int playerArmor;
		static int playerWeapon;
		static int playerHp;
		static int playerAtk;
		static vector<unique_ptr<Item>>playerItems;
	};
}


