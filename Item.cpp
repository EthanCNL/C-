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

    }

    Item::~Item() {}
}
