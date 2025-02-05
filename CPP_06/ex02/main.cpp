#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base *ptr;

    ptr = generate();

    identify(ptr);

    identify(*ptr);
    
    delete ptr;
    return (0); 
}