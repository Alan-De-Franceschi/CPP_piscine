#include "easyfind.hpp"

int main(void)
{
    std::list<int>  myList;
    for (int i = 0; i < 10; i++)
        myList.push_back(i);

    std::vector<int> myVector;
    for (int i = 0; i < 10; i++)
        myVector.push_back(i);

    int             num = 0;

    if (easyfind(myList, num))
    {
        std::cout
            << GREEN
            << "Num = "
            << num
            << " is in myList"
            << END
            << std::endl;
    }
    else
    {
        std::cout
            << RED
            << "Num = "
            << num
            << " is not in myList"
            << END
            << std::endl;
    }

    if (easyfind(myVector, num))
    {
        std::cout
            << GREEN
            << "Num = "
            << num
            << " is in myVector"
            << END
            << std::endl;
    }
    else
    {
        std::cout
            << RED
            << "Num = "
            << num
            << " is not in myVector"
            << END
            << std::endl;
    }
}