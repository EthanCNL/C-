#pragma once
#include <string>
#include "Room.h"
using namespace std;
namespace En {
	class Encounter
	{
	public:
		Encounter();
		~Encounter();
		void Fight();
		void EnemyAttack();
		void EnemyHeal();
		bool isPlayerTurn;
		string action;
		void Run();
		void Core(int enemyNum, int roomNum, std::vector<std::unique_ptr<Room>>& rooms);
		int blockModifier;

	};

}

