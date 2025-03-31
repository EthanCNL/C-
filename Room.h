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
        static std::vector<unique_ptr<Enem::Enemy> > enemies; // unique_ptr allows for polymorphism to multiple enemy types
        std::vector<string> loot;
        std::vector<int> adjacentRooms;
        int currentEnemy;
        Room();
        void AddEnemy(std::unique_ptr<Enem::Enemy> enemy);
        void AddLoot(const string& item);
        void AddAdjacentRoom(int roomNum);
        static void DisplayRoomInfo();
        void SetEnemyNum(int num);
        void SetRoomNum(int num);
    };
}


#endif // !ROOM_H

