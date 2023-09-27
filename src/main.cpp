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
        new Weapon("Sword", 1, 10, 50); // name, rarity, price, damage
    Weapon *staff = new Weapon("Staff", 1, 10, 50);

    Consumable *potion =
        new Consumable("Potion", 1, 10, 50); // name, rarity, price, health

    Knight dornar("Dornar");
    dornar.equip(sword);
    dornar.display();

    Wizard gandalf("Gandalf");
    gandalf.equip(staff);
    gandalf.use(potion);
    gandalf.display();

    while (dornar.isAlive() && gandalf.isAlive())
    {
        dornar.attack(gandalf);
        gandalf.attack(dornar);
    }

    dornar.display();
    gandalf.display();

    delete staff;
    delete sword;
    delete potion;
    return 0;
}
