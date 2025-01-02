#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap    pinky("Pinky");
    ScavTrap    glam("Glam");
    ScavTrap    glamCpy(glam);
    ClapTrap    oldOne("Old One");

    std::cout << std::endl << GREEN << "===== TEST 1 =====" << END << std::endl << std::endl;

    pinky.attack(glam.getName());
    glam.takeDamage(pinky.getAttack());
    std::cout << std::endl;
    pinky.showStats();
    glam.showStats();
    std::cout << std::endl;
    pinky.takeDamage(50);
    pinky.showStats();
    pinky.takeDamage(50);
    pinky.showStats();
    pinky.takeDamage(50);
    std::cout << std::endl;
    pinky.attack(glam.getName());
    pinky.beRepaired(10);

    std::cout << std::endl << GREEN << "===== TEST 2 =====" << END << std::endl << std::endl;

    for (int i = 0; i <= 50; i++)
        glam.attack(pinky.getName());
    glam.showStats();
    glam.beRepaired(10);
    glam.showStats();

    std::cout << std::endl << GREEN << "===== TEST 3 =====" << END << std::endl << std::endl;

    glamCpy.beRepaired(10);
    glamCpy.showStats();
    glamCpy.takeDamage(5);
    glamCpy.showStats();
    glamCpy.beRepaired(500);
    glamCpy.showStats();

    std::cout << std::endl << GREEN << "===== TEST 4 =====" << END << std::endl << std::endl;

    oldOne.attack(glamCpy.getName());
    glamCpy.attack(oldOne.getName());

    std::cout << std::endl << GREEN << "===== TEST 5 =====" << END << std::endl << std::endl;

    glamCpy.guardGate();
    glamCpy.guardGate();

    std::cout << std::endl << std::endl;
    return (0);
}
