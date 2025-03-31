//Enemy.h
#ifndef ENEMY_H
#define ENEMY_H
#include<iostream>
#include<string>
using namespace std;
namespace Enem {
	class Enemy {
	public:
		static int count;
		int HP;
		int ATK;
		int weaponPoints;
		int armorPoints;
		string monsterType;
		string gearName;
		int ReturnHP();
		int ReturnATK();
		int ReturnAP();
		int ReturnWP();
		void SetHP(int num);
		string ReturnName();
		Enemy();
		void Count();
	};

	class Slime : public Enemy {
	public:
		Slime();
	};

	class Goblin : public Enemy {
	public:
		Goblin();
	};
	class Orc : public Enemy {
	public:
		Orc();
	};
	class Skeleton : public Enemy {
	public:
		Skeleton();
	};

}
#endif