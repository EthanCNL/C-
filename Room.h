
#ifndef ROOM_H
#define ROOM_H
//#include "Enemy.h"
#include <vector>
#include <string>
#include <memory>


class Room {
    int roomNumber;
    std::vector<unique_ptr<Enemy>> enemies; // unique_ptr allows for polymorphism to multiple enemy types
    std::vector<string> loot;
    std::vector<int> adjacentRooms;

    void AddEnemy(std::unique_ptr<Enemy> enemy);
    void AddLoot(const string& item);
    void AddAdjacentRoom(int roomNum);
    void DisplayRoomInfo() const;
};

#endif // !ROOM_H

