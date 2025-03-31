//Enemy.cpp
#include "Enemy.h"
#include <string>
using namespace std;
namespace Enem {
	int Enemy::count = 0;
	int HP;
	int weaponPoints;
	int armorPoints;
	int ATK;
	string monsterType;
	EquipableItem item;

	//Enemy Constructor and destructor
	Enemy::Enemy() {
		HP = 0;
		weaponPoints = 0;
		armorPoints = 0;
		ATK = 0;
		monsterType = "";
	}

	//Count function to tell the user how many enemies there are in the hypothetical room generated in the game
	void Enemy::Count() {
		cout << "Enemies in the Room: " << ++Enemy::count - 1 << "\n";
	}

	int Enemy::ReturnHP()
	{
		return HP;
	}
	int Enemy::ReturnATK()
	{
		return ATK;	
	}
	int Enemy::ReturnAP()
	{
		return armorPoints;
	}
	int Enemy::ReturnWP()
	{
		return weaponPoints;
	}

	void Enemy::SetHP(int num)
	{
		HP = num;
	}

	string Enemy::ReturnName()
	{
		return monsterType;
	}
	Slime::Slime()
	{
		monsterType = "Slime";
		HP = 25;
		ATK = 5;
	}

	Orc::Orc()
	{
		monsterType = "Orc";
		HP = 100;
		ATK = 25;
	}

	Goblin::Goblin()
	{
		monsterType = "Goblin";
		HP = 50;
		ATK = 15;
		armorPoints = 5;
		weaponPoints = 2;
	}

	Skeleton::Skeleton()
	{
		monsterType = "Skeleton";
		HP = 40;
		ATK = 20;
		weaponPoints = 3;
	}

}