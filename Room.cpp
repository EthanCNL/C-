#include "Room.h"
#include <iostream>
#include "Enemy.h"
#include <random>
using namespace std;
using namespace Enem;

namespace RoomG
{
	std::vector<std::unique_ptr<Enem::Enemy>> Room::enemies;
	int Room::roomNumber = 1;
	int Room::enemyNum = 0;

	Room::Room()
	{
		int randomEnemyNum = rand() % 3;
		for (int i = 0; i <= randomEnemyNum; i++)
		{
			int randomEnemyType = rand() % 4;
			if (randomEnemyType == 0)
			{
				AddEnemy(make_unique<Slime>());
			}
			if (randomEnemyType == 1)
			{
				AddEnemy(make_unique<Goblin>());
			}
			if (randomEnemyType == 2)
			{
				AddEnemy(make_unique<Orc>());
			}
			if (randomEnemyType == 3)
			{
				AddEnemy(make_unique<Skeleton>());
			}
		}
	}


	void Room::SetEnemyNum(int num)
	{
		enemyNum = num;
	}

	void Room::SetRoomNum(int num)
	{
		roomNumber = num;
	}

	void Room::AddEnemy(std::unique_ptr<Enem::Enemy> enemy) {
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
}
