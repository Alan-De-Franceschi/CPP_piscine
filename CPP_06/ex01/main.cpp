#include "Serializer.hpp"

int main(void)
{
    Data   a;
    a.name = "Pinky";
    a.age = 42;

    Data*   b = Serializer::deserialize(Serializer::serialize(&a));

    std::cout
        << "a.name = " << a.name
        << " a.age = " << a.age
        << std::endl
        << "b->name " << b->name
        << " b->age = " << b->age
        << std::endl;

    return (0); 
}