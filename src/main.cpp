/*
Loïs GALLAUD
https://github.com/LOISGALLAUD
*/

#include "../include/Armor.hpp"
#include "../include/Consumable.hpp"
#include "../include/Golem.hpp"
#include "../include/Item.hpp"
#include "../include/Knight.hpp"
#include "../include/Weapon.hpp"
#include "../include/Wizard.hpp"
#include "../include/interface.hpp"

int main()
{
    Weapon sword =
        Weapon("Excalibur", 1, 10, 50); // name, rarity, price, damage
    Armor helmet =
        Armor("Helmet", 1, 10, 50); // name, rarity, price, damage reduction
    Knight dornar("Dornar");
    Golem gomata("Gomata");

    dornar.equip(&sword);
    gomata.wear(&helmet);
    dornar.attack(gomata);

    std::cout << gomata << std::endl;

    return 0;
}
