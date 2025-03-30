

#ifndef EVENT_H
#define EVENT_H
#include <Player.h>
#include <Room.h> //room header file has <vector> and <string> already defined so i wont define again


class Event {

	void TriggerEvent(Room& currentRoom, float& playerHp, float& playerArmor, std::list<string>& playerItems);

};


#endif 