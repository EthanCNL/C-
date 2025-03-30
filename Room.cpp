

#include <Room.h>
#include <iostream>

void Room::AddEnemy(std::unique_ptr<Enemy> enemy) {

	enemies.push_back(std::move(enemy));

}
void Room::AddLoot(const std::string& item) {

	loot.push_back(item);
}
void Room::AddAdjacentRoom(int roomNum) {

	adjacentRooms.push_back(roomNum);
}
void Room::DisplayRoomInfo() {

	cout << "Room: " << roomNumber << "\n";
	cout << "Enemies: " << enemies.size() << "\n";

}