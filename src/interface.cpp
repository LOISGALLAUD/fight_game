#include "../include/interface.hpp"

void equipWeaponTo(Character &character)
{
    if (character.isInventoryEmpty())
    {
        std::cout << character.getName() << "'s inventory is empty."
                  << std::endl;
    }
    else
    {
        character.displayInventory();
        std::cout << "Choose an item to equip:" << std::endl;
        Weapon *weaponToEquip = character.chooseWeapon(); // Copy of the pointer
        if (weaponToEquip != nullptr)
        {
            character.unequip();
            character.equip(weaponToEquip);
            int index = character.getIndexOf(weaponToEquip);
            character.deleteItem(index);
        }
    }
}
