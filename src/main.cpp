/*
Loïs GALLAUD
https://github.com/LOISGALLAUD
*/

#include "../include/Golem.hpp"
#include "../include/Item.hpp"
#include "../include/Knight.hpp"
#include "../include/Weapon.hpp"
#include "../include/Wizard.hpp"

int main()
{
    Weapon *sword =
        new Weapon("Sword", 1, 10, 50); // name, rarity, price, damage

    Weapon *staff = new Weapon("Staff", 1, 10, 50);

    Knight dornar("Dornar");
    dornar.equip(sword);
    dornar.displayInfo();

    Wizard gandalf("Gandalf");
    gandalf.equip(staff);
    gandalf.displayInfo();

    while (dornar.isAlive() && gandalf.isAlive())
    {
        dornar.attack(gandalf);
        gandalf.attack(dornar);
    }

    dornar.displayInfo();
    gandalf.displayInfo();

    delete staff;
    delete sword;
    return 0;
}
