#pragma once
#include <string>
#include "Room.h"
#include "Enemy.h"
using namespace std;
namespace En {
	class Encounter
	{
	public:
		Encounter();
		~Encounter();
		void Fight(std::unique_ptr<Enem::Enemy>& enemy);
		void EnemyAttack();
		void EnemyHeal();
		bool isPlayerTurn;
		string action;
		void Run();
		void Core(std::unique_ptr<Enem::Enemy>& enemy);
		int blockModifier;
		static bool won;
	};

}

