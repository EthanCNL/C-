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
		void CoreLoop();
		bool ReturnCombat();
		void SetCombat(bool input);
	};
}


