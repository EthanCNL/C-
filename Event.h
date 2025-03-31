#ifndef EVENT_H
#define EVENT_H
//#include "Player.h"
#include "Room.h" //room header file has <vector> and <string> already defined so i wont define again
#include <string>
#include <list>

using namespace std;
using namespace RoomG;

namespace Even
{
	class Event {
		void TriggerEvent();
	};
}
#endif 