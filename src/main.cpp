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
#include <locale>

int main()
{
    Weapon *sword =
        new Weapon("Excalibur", 1, 10, 50); // name, rarity, price, damage
    Weapon *staff = new Weapon("Staff", 1, 10, 50);

    Consumable *potion =
        new Consumable("Potion", 1, 10, 50); // name, rarity, price, health

    Knight dornar("Dornar");
    dornar.collect(sword);
    dornar.equip(sword);
    std::cout << dornar;

    Wizard gandalf("Gandalf");
    gandalf.equip(staff);
    gandalf.use(potion);
    std::cout << gandalf;

    while (dornar.isAlive() && gandalf.isAlive())
    {
        dornar.attack(gandalf);
        gandalf.attack(dornar);
    }

    std::cout << dornar;
    std::cout << gandalf;

    delete staff;
    delete sword;
    return 0;
}
