#include "Room.h"
#include <iostream>
#include "Enemy.h"
#include <random>
using namespace std;
using namespace Enem;

namespace RoomG
{
	std::vector<std::unique_ptr<Enem::Enemy>> enemies;
	int Room::roomNumber = 0;
	int Room::enemyNum = 0;
	int enemiesLeft = 0;

	Room::Room()
	{
		
	}

	void Room::IncrementEnemies()
	{
		enemiesLeft++;
	}

	int Room::GetEnemiesLeft()
	{
		return enemiesLeft;
	}

	void Room::AddEnemy(std::unique_ptr<Enem::Enemy> enemy) {
		enemies.push_back(std::move(enemy));

	}

	void Room::RemoveEnemy() {
		enemies.erase(enemies.begin());
		enemiesLeft--;
	}
	void Room::AddLoot(const std::string& item) {
		loot.push_back(item);
	}
	void Room::AddAdjacentRoom(int roomNum) {

		adjacentRooms.push_back(roomNum);
	}
	void Room::DisplayRoomInfo(int num) {
		cout << "Room: " << roomNumber + 1 << "\n";
		cout << "Enemies: " << num << "\n";
	}

	std::unique_ptr<Enem::Enemy>& Room::ReturnEnemy(int num)
	{
		return enemies.at(num);
	}
}
