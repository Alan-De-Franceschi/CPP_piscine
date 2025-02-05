#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

struct Data
{
    std::string name;
    int         age;
};

class   Serializer
{
    public:

        Serializer(void);
        Serializer(const Serializer & src);
        virtual ~Serializer(void) = 0;

        Serializer &    operator=(const Serializer & rhs);

        static uintptr_t       serialize(Data* ptr);
        static Data*           deserialize(uintptr_t raw);

    private:

};

#endif