#include "Inventory.h"

using namespace std;

namespace Inven
{
    const int MAX_INVENTORY_SIZE = 5;
    vector<std::unique_ptr<Item>> Inventory::inventory;
    unique_ptr<EquipableItem> Inventory::left_hand;
    unique_ptr<EquipableItem> Inventory::right_hand;

    void Inventory::ShowEquipment() {
        std::cout << "\nCurrently Equipped:\n";
        std::cout << "Left Hand:  " << (left_hand ? left_hand->GetName() : "Empty") << "\n";
        std::cout << "Right Hand: " << (right_hand ? right_hand->GetName() : "Empty") << "\n";
    }



    bool Inventory::AddToInventory(std::unique_ptr<Item> item) {
        if (inventory.size() >= MAX_INVENTORY_SIZE) {
            std::cout << "Your backpack is full! Frankly you shouldn't even be able to do it in this demo but good on you!" << item->GetName() << ".\n";
            return false;
        }
        inventory.push_back(std::move(item));
        return true;
    }




    void Inventory::EquipItem(std::unique_ptr<EquipableItem> item) {
        ShowEquipment();
        std::cout << "You're holding in your left hand "
            << (left_hand ? left_hand->GetName() : "nothing")
            << " and in your right hand "
            << (right_hand ? right_hand->GetName() : "nothing")
            << ".\n";
        std::cout << "Which hand will wield the " << item->GetName() << "? (L/R): ";
        char choice;
        std::cin >> choice;





        if (choice == 'L' || choice == 'l') {
            if (left_hand) {

                std::cout << "Left hand is already holding " << left_hand->GetName() << ".\n";
                std::cout << "Do you want to swap it out? Press Y/N: ";
                char confirm;
                std::cin >> confirm;
                if (std::tolower(confirm) != 'y') {

                    std::cout << "You changed your mind and put it back.\n";
                    AddToInventory(std::move(item));
                    return;
                }
                AddToInventory(std::move(left_hand));
            }
            left_hand = std::move(item);
            std::cout << "Equipped in left hand! ";
        }

        else if (choice == 'R' || choice == '2') {
            if (right_hand) {

                std::cout << "Right hand is already holding " << right_hand->GetName() << ".\n";
                std::cout << "Do you want to swap it out? Press Y/N: ";
                char confirm;
                std::cin >> confirm;
                if (std::tolower(confirm) != 'y') {

                    std::cout << "You changed your mind and put it back.\n";
                    AddToInventory(std::move(item));
                    return;
                }
                AddToInventory(std::move(right_hand));
            }
            right_hand = std::move(item);
            std::cout << "Equipped in right hand!";
        }

        else {
            std::cout << "You Can't do that.\n";
            AddToInventory(std::move(item));
            return;
        }




        if ((choice == 'L' || choice == 'l') && left_hand) {
            if (left_hand->GetAttack() > 0)
                std::cout << "You get +" << left_hand->GetAttack() << " attack!\n";

            else if (left_hand->GetDefense() > 0)
                std::cout << "You get +" << left_hand->GetDefense() << " defense!\n";
        }
        if ((choice == 'R' || choice == 'r') && right_hand) {
            if (right_hand->GetAttack() > 0)
                std::cout << "You get +" << right_hand->GetAttack() << " attack!\n";

            else if (right_hand->GetDefense() > 0)
                std::cout << "You get +" << right_hand->GetDefense() << " defense!\n";
        }
    }
}
