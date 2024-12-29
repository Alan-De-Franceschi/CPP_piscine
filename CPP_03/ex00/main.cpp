#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    pinky("Pinky");
    ClapTrap    glam("Glam");
    ClapTrap    test(glam);

    std::cout << std::endl << GREEN << "===== TEST 1 =====" << END << std::endl << std::endl;

    pinky.attack(glam.getName());
    glam.takeDamage(pinky.getAttack());
    std::cout << std::endl;
    pinky.showStats();
    glam.showStats();
    std::cout << std::endl;
    pinky.takeDamage(2);
    pinky.showStats();
    pinky.takeDamage(8);
    pinky.showStats();
    pinky.takeDamage(2);
    std::cout << std::endl;
    pinky.attack(glam.getName());
    pinky.beRepaired(10);

    std::cout << std::endl << GREEN << "===== TEST 2 =====" << END << std::endl << std::endl;

    for (int i = 0; i <= 10; i++)
        glam.attack(pinky.getName());
    glam.showStats();
    glam.beRepaired(10);

    std::cout << std::endl << GREEN << "===== TEST 3 =====" << END << std::endl << std::endl;

    test.beRepaired(10);
    test.showStats();
    test.takeDamage(5);
    test.showStats();
    test.beRepaired(500);
    test.showStats();

    std::cout 
        << std::endl
        << std::endl;
    return (0);
}