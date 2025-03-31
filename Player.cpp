#include "Player.h"
#include <list>
#include <string>

namespace Play
{
	int Player::playerArmor = 0;
	int Player::playerWeapon = 0;
	int Player::playerHp = 100;
	int Player::playerAtk = 25;
	vector<unique_ptr<Item>> playerItems;
}