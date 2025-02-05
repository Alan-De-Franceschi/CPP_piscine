#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void)
{
    static bool randomGenerator = false;
    Base        *ptr = NULL;
    int         random;

    if (!randomGenerator)
    {
        std::srand(std::time(NULL));
        randomGenerator = true;
    }
    random = std::rand();
    if (random % 3 == 0)
        ptr = new A();
    else if (random % 3 == 1)
        ptr = new B();
    else
        ptr = new C();
    return (ptr);
}

void    identify(Base* p)
{
    A*  testA;
    B*  testB;
    C*  testC;

    testA = dynamic_cast<A*>(p);
    if (testA)
    {
        std::cout
            << "pointer   -> TYPE A"
            << std::endl;
        return ;
    }
    testB = dynamic_cast<B*>(p);
    if (testB)
    {
        std::cout
            << "pointer   -> TYPE B"
            << std::endl;
        return ;
    }
    testC = dynamic_cast<C*>(p);
    if (testC)
    {
        std::cout
            << "pointer   -> TYPE C"
            << std::endl;
        return ;
    }
}

void identify(Base& p)
{
    A  testA;
    B  testB;
    C  testC;

    try
    {
        testA = dynamic_cast<A&>(p);
        std::cout
            << "reference -> TYPE A"
            << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        testB = dynamic_cast<B&>(p);
        std::cout
            << "reference -> TYPE B"
            << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        testC = dynamic_cast<C&>(p);
        std::cout
            << "reference -> TYPE C"
            << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    return ;
}