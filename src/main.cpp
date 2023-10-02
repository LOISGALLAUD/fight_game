/*
Loïs GALLAUD
https://github.com/LOISGALLAUD
*/

#include "../include/Consumable.hpp"
#include "../include/Golem.hpp"
#include "../include/Item.hpp"
#include "../include/Knight.hpp"
#include "../include/Weapon.hpp"
#include "../include/Wizard.hpp"

int main()
{
    Weapon *sword =
        new Weapon("Excalibur", 1, 10, 50); // name, rarity, price, damage
    // Weapon *staff = new Weapon("Staff", 1, 10, 50);
    //
    // Consumable *potion =
    //     new Consumable("Potion", 1, 10, 50); // name, rarity, price, health

    Knight dornar("Dornar");
    dornar.collect(sword);
    // delete sword;
    // dornar.equip(sword);

    std::cout << dornar;
    // dornar.displayInventory();
    // dornar.setMoney(15);
    // dornar.collect(potion);

    // delete potion;
    // delete staff;
    // delete sword;
    return 0;
}
