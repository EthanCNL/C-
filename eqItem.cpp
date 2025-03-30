#include "eqItem.h"
#include <iostream>

namespace IItem {
    EquipableItem::EquipableItem(const std::string& itemName, int atk, int def)
        : Item(itemName), attack_bonus(atk), defense_bonus(def) {}

    void EquipableItem::Use() const {
    }

    int EquipableItem::GetAttack() const {
        return attack_bonus;
    }

    int EquipableItem::GetDefense() const {
        return defense_bonus;
    }
}
