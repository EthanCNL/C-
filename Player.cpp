#include "Player.h"
#include <list>
#include <string>

namespace Play
{
	int Player::playerArmor;
	int Player::playerWeapon;
	float Player::playerHp;
	float Player::playerAtk;
	vector<unique_ptr<Item>> playerItems;
}