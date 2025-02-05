#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base *ptr = NULL;

    try
    {
        ptr = generate();

        identify(ptr);

        identify(*ptr);

        delete ptr;
    }
    catch (const std::exception& e)
    {
        delete ptr;
        std::cerr << e.what() << std::endl;
    }
    return (0); 
}