#include "easyfind.hpp"

int main(void)
{
    std::list<int>  myList;
    for (int i = 0; i < 10; i++)
        myList.push_back(i);

    std::vector<int> myVector;
    for (int i = 0; i < 10; i++)
        myVector.push_back(i);

    int             num = 2;

    std::cout
        << "Is num in list = "
        << easyfind(myList, num)
        << std::endl;

    std::cout
        << "Is num in vector = "
        << easyfind(myVector, num)
        << std::endl;
    return (0);
}