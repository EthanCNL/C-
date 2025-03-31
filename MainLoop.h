#pragma once
#include <string>
//Main Loop header
using namespace std;
namespace Loop {
	class MainLoop
	{
	public:
		static bool inCombat;
		string action;
		MainLoop();
		~MainLoop();
		void CoreLoop(int num);
		bool ReturnCombat();
		void SetCombat(bool input);
	};
}


