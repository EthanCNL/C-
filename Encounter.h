#pragma once
#include <string>
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
		void Core();
		int blockModifier;

	};

}

