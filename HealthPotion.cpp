#include "healthPotion.h"
#include <iostream>
#include <string>

namespace IItem {
    HealthPotion::HealthPotion() : Item("Health Potion") {}

    void HealthPotion::Use() const {
        std::cout << "You take a hearty swig from the health potion, it's got a gentle cheery aftertaste and feels like a warm hug through your entire body. Hp has been restored to fulL!\n";       
    }
}
