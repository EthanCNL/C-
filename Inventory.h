#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cctype>

#include "item.h"
#include "healthPotion.h"
#include "eqItem.h"

using namespace IItem;
using namespace std;


namespace Inventory
{
    class Inventory {
    public:
        const int MAX_INVENTORY_SIZE = 5;
        vector<std::unique_ptr<Item>> inventory;
        unique_ptr<EquipableItem> left_hand = nullptr;
        unique_ptr<EquipableItem> right_hand = nullptr;
        void ShowEquipment();
        bool AddToInventory(unique_ptr<Item> item);
        void EquipItem(unique_ptr<EquipableItem> item);
    };
}


