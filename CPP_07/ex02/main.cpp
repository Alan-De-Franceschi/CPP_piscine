#include "Array.hpp"

int main(void) 
{
    try
    {
        Array<int>  defarray(4);

        std::cout << std::endl << GREEN << "Default Array:" << END << std::endl;
        for (unsigned int i = 0; i < defarray.size(); i++)
            std::cout << defarray[i] << std::endl;
        std::cout << std::endl;

        Array<int>  iarray(4);
        iarray[0] = 0;
        iarray[1] = 1;
        iarray[2] = 2;
        iarray[3] = 3;
        //iarray[4] = 4;

        std::cout << std::endl << GREEN << "Int Array:" << END << std::endl;
        for (unsigned int i = 0; i < iarray.size(); i++)
            std::cout << iarray[i] << std::endl;
        std::cout << std::endl;
        
        Array<std::string>  sarray(4);
        sarray[0] = "Pinky";
        sarray[1] = "Glam";
        sarray[2] = "Kendrick";
        sarray[3] = "SZA";
        //sarray[4] = "LOL";

        std::cout << std::endl << GREEN << "Str Array:" << END << std::endl;
        for (unsigned int i = 0; i < sarray.size(); i++)
            std::cout << sarray[i] << std::endl;
        std::cout << std::endl;

        Array<double>  darray(4);
        darray[0] = 0.0;
        darray[1] = 1.0;
        darray[2] = 2.0;
        darray[3] = 3.0;
        //darray[4] = 4.0;

        std::cout << std::endl << GREEN << "Double Array:" << END << std::endl;
        for (unsigned int i = 0; i < darray.size(); i++)
            std::cout << std::fixed << std::setprecision(1) << darray[i] << std::endl;
        std::cout << std::endl;

        const Array<int> carray(iarray);

        std::cout << std::endl << GREEN << "Const Array:" << END << std::endl;
        for (unsigned int i = 0; i < carray.size(); i++)
            std::cout << carray[i] << std::endl;
        std::cout << std::endl;

        Array<int> copy_array(iarray);

        std::cout << std::endl << GREEN << "Copy Array:" << END << std::endl;
        for (unsigned int i = 0; i < copy_array.size(); i++)
            std::cout << carray[i] << std::endl;
        std::cout << std::endl;

        copy_array[0] = 500;

        std::cout << std::endl << BLUE << "Test deep copy:" << END <<std::endl << GREEN << std::endl << "Int Array:" << END << std::endl;
        for (unsigned int i = 0; i < iarray.size(); i++)
            std::cout << iarray[i] << std::endl;

        std::cout << std::endl << GREEN << "Copy Array:" << END << std::endl;
        for (unsigned int i = 0; i < copy_array.size(); i++)
            std::cout << copy_array[i] << std::endl;
        std::cout << std::endl;

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
