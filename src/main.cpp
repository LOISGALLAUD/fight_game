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
#include "interface.cpp"

int main()
{
    Weapon *sword =
        new Weapon("Excalibur", 1, 10, 50); // name, rarity, price, damage
    Knight dornar("Dornar");
    Wizard gandalf("Gandalf");
    gandalf.addMoney(1000);
    gandalf.pay(dornar, 100);
    dornar.displayInventory();
    gandalf.displayInventory();
    return 0;
}
