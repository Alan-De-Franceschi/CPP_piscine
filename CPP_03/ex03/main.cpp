#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap pinky("Pinky");
    std::cout
        << std::endl;
    ScavTrap    glam("Glam");
    std::cout
        << std::endl;
    FragTrap    fluo("Fluo");

    std::cout << std::endl << GREEN << "===== TEST 1 =====" << END << std::endl << std::endl;

    pinky.whoAmI();

    std::cout << std::endl << GREEN << "===== TEST 2 =====" << END << std::endl << std::endl;

    pinky.showStats();
    glam.showStats();
    fluo.showStats();

    std::cout << std::endl << GREEN << "===== TEST 3 =====" << END << std::endl << std::endl;

    pinky.attack("test");
    glam.attack("test");
    fluo.attack("test");

    std::cout << std::endl << GREEN << "===== TEST 4 =====" << END << std::endl << std::endl;

    pinky.guardGate();
    pinky.highFivesGuys();

    std::cout
        << std::endl
        << std::endl;
    return (0);
}
