#include "Array.hpp"

int main(void) 
{
    try
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

        Array<int>  iarray(4);
        iarray[0] = 0;
        iarray[1] = 1;
        iarray[2] = 2;
        iarray[3] = 3;
        //iarray[4] = 4;

        std::cout << std::endl << "Int Array:" << std::endl;
        for (unsigned int i = 0; i < iarray.size(); i++)
            std::cout << iarray[i] << std::endl;
        
        Array<std::string>  sarray(4);
        sarray[0] = "Pinky";
        sarray[1] = "Glam";
        sarray[2] = "Kendrick";
        sarray[3] = "SZA";
       // sarray[4] = "LOL";

        std::cout << std::endl << "Str Array:" << std::endl;
        for (unsigned int i = 0; i < sarray.size(); i++)
            std::cout << sarray[i] << std::endl;

        const Array<int> carray(iarray);

        std::cout << std::endl << "Const Array:" << std::endl;
        for (unsigned int i = 0; i < carray.size(); i++)
            std::cout << carray[i] << std::endl;

    }
    catch(const std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
    }
    return (0);
}
