#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 1                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;
    {
        const Animal* meta = new Animal();
        std::cout << std::endl;

        const Animal* j = new Dog();
        std::cout << std::endl;

        const Animal* i = new Cat();
        std::cout << std::endl;

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << std::endl;

        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        std::cout << std::endl;

        delete i;
        delete j;
        delete meta;
    }
    std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 2                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;
    {
        const Animal* meta = new Animal();
        std::cout << std::endl;

        const Animal* j = new Dog();
        std::cout << std::endl;

        const WrongAnimal* i = new WrongCat();
        std::cout << std::endl;

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << std::endl;
        
        j->makeSound(); //will output the WrongAnimal sound!
        i->makeSound();
        meta->makeSound();
        std::cout << std::endl;

        delete i;
        delete j;
        delete meta;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return (0);
}
