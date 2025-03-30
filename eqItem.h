#ifndef EQITEM_H
#define EQITEM_H

#include "Item.h"

namespace IItem {
    class EquipableItem : public Item {
    protected:
        int attack_bonus;
        int defense_bonus;

    public:
        EquipableItem(const std::string& itemName, int atk = 0, int def = 0);
        void Use() const override;
        int GetAttack() const;
        int GetDefense() const;
    };
}

#endif
