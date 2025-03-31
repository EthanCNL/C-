#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

namespace IItem {
    class Item {
    protected:
        std::string name;

    public:
        Item(const std::string& itemName);
        virtual void Use() const;
        virtual void PrintInfo() const;
        std::string GetName() const;
        virtual ~Item();
    };
}

#endif
