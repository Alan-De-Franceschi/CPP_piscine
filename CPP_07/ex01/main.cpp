#include "iter.hpp"

int main(void) 
{
    float       farray[4] = {0.0, 1.0, 2.0, 3.0};
    int         iarray[4] = {0, 1, 2, 3};
    std::string sarray[4] = {"Pinky", "Lol", "Test", "Test2"};

    iter(farray, 4, &up);
    iter(iarray, 4, &up);
    iter(sarray, 4, &rename);

    std::cout << "Float array = " << std::flush;
    for (int i = 0; i < 4; i++)
    {
        std::cout << farray[i] << std::flush;
        if (i < 3)
            std::cout << ", " << std::flush;
    }

    std::cout << std::endl << "Int array = " << std::flush;
    for (int i = 0; i < 4; i++)
    {
        std::cout << iarray[i] << std::flush;
        if (i < 3)
            std::cout << ", " << std::flush;
    }

    std::cout << std::endl << "String array = " << std::flush;
    for (int i = 0; i < 4; i++)
    {
        std::cout << sarray[i] << std::flush;
        if (i < 3)
            std::cout << ", " << std::flush;
    }

    std::cout << std::endl;
    return (0);
}
