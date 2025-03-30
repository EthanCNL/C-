#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Item.h"

namespace IItem {
    class HealthPotion final : public Item {
    public:
        HealthPotion();
        void Use() const final override;
    };
}

#endif
