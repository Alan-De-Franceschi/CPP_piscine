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

    Animal* array[4];

    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            array[i] = new Dog();
        else
            array[i] = new Cat();
    }
    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
    {
        std::cout << i + 1 << " " << std::flush;
        array[i]->makeSound();
    }
    std::cout << std::endl;

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
    
    for (int i = 0; i < 100; i++)
    {
        std::cout 
            << array[0]->getIdea(i)
            << std::endl;
    }
    std::cout << std::endl;

    array[0]->setIdea(4, "The greatest idea !!!");
    for (int i = 0; i < 10; i++)
    {
        std::cout 
            << array[0]->getIdea(i)
            << std::endl;
    }
    std::cout << std::endl;


    std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 3                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

    Dog*    pinky = new Dog();
    std::cout << std::endl;
    Dog*    glam = new Dog(*pinky);
    std::cout << std::endl;
    Dog     rose(*pinky);
    std::cout << std::endl;
    delete pinky;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout 
            << glam->getIdea(i)
            << std::endl;
    }
    std::cout << std::endl;
    
    for (int i = 0; i < 10; i++)
    {
        std::cout 
            << glam->getIdea(i)
            << std::endl;
    }
    std::cout << std::endl;


    std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==               Destructeur glam             =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;
    delete glam;
    
    std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==               Destructeur array            =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;
    for (int i = 0; i < 4; i++)
        delete array[i];

    std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==             Destructeur rose               =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;
    return (0);
}
