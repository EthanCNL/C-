#include "Player.h"
#include <list>
#include <string>

namespace Play
{
	int Player::playerArmor;
	int Player::playerWeapon;
	int Player::playerHp;
	int Player::playerAtk;
	vector<unique_ptr<Item>> playerItems;
}