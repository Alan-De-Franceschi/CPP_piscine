#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap    pinky("Pinky");
    FragTrap    glam("Glam");
    FragTrap    pinkyCpy(glam);
    ScavTrap    creepy("Creepy");
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

    for (int i = 0; i <= 100; i++)
        glam.attack(pinky.getName());
    glam.showStats();
    glam.beRepaired(10);
    glam.showStats();

    std::cout << std::endl << GREEN << "===== TEST 3 =====" << END << std::endl << std::endl;

    pinkyCpy.beRepaired(10);
    pinkyCpy.showStats();
    pinkyCpy.takeDamage(5);
    pinkyCpy.showStats();
    pinkyCpy.beRepaired(500);
    pinkyCpy.showStats();

    std::cout << std::endl << GREEN << "===== TEST 4 =====" << END << std::endl << std::endl;

    oldOne.attack(pinkyCpy.getName());
    pinkyCpy.attack(oldOne.getName());

    std::cout << std::endl << GREEN << "===== TEST 5 =====" << END << std::endl << std::endl;

    creepy.guardGate();
    creepy.guardGate();

    std::cout << std::endl << GREEN << "===== TEST 6 =====" << END << std::endl << std::endl;

    pinkyCpy.highFivesGuys();

    std::cout << std::endl << std::endl;
    return (0);
}
