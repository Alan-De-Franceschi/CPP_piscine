#include "Serializer.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Serializer::Serializer(void)
{
    std::cout
        << BLUE
        << "Serializer: Constructor Called"
        << END
        << std::endl;
    return ;
}

Serializer::Serializer(const Serializer & src)
{
    (void)src;
    std::cout
        << BLUE
        << "Serializer: Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

Serializer::~Serializer(void)
{
    std::cout
        << BLUE
        << "Serializer: Destructor Called"
        << END
        << std::endl;
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Serializer &    Serializer::operator=(const Serializer & rhs)
{
    (void)rhs;
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

uintptr_t   Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    Data* newData = reinterpret_cast<Data*>(raw);
    return (newData);
}