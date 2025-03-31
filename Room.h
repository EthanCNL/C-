#ifndef ROOM_H
#define ROOM_H
//#include "Enemy.h"
#include <vector>
#include <string>
#include <memory>
#include "Enemy.h"

namespace RoomG
{
    class Room {
    public:
        static int roomNumber;
        static int enemyNum;
        int enemiesLeft;
        vector<unique_ptr<Enem::Enemy> > enemies; // unique_ptr allows for polymorphism to multiple enemy types
        std::vector<string> loot;
        std::vector<int> adjacentRooms;
        int currentEnemy;
        Room();
        void AddEnemy(std::unique_ptr<Enem::Enemy> enemy);
        void RemoveEnemy();
        void AddLoot(const string& item);
        void AddAdjacentRoom(int roomNum);
        static void DisplayRoomInfo(int num);
        void IncrementEnemies();
        int GetEnemiesLeft();
        std::unique_ptr<Enem::Enemy>& ReturnEnemy(int num);
    };
}


#endif // !ROOM_H

