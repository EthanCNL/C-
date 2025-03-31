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


namespace Inven
{
    class Inventory {
    public:
        static const int MAX_INVENTORY_SIZE = 5;
        static vector<std::unique_ptr<Item>>inventory;
        static unique_ptr<EquipableItem> left_hand;
        static unique_ptr<EquipableItem> right_hand;
        void ShowEquipment();
        bool AddToInventory(unique_ptr<Item> item);
        void EquipItem(unique_ptr<EquipableItem> item);
    };
}


