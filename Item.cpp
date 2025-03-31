#include "Item.h"

namespace IItem {
    Item::Item(const std::string& itemName) : name(itemName) {}

    void Item::PrintInfo() const {
        std::cout << "Item: " << name << "\n";
    }

    std::string Item::GetName() const {
        return name;
    }

    void Item::Use() const
    {
        
     std::cout << "You use the " << name << ".\n";
    
    if (name == "Health Potion") {
        std::cout << "Restores 25 HP!\n";
    }
    else if (name == "Armor") {
        std::cout << "Restores 15 armor!\n";
    }
    else {
        std::cout << "Nothing happened!! Select an item \n";
    }

    }

    Item::~Item() {}
}
