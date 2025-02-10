#ifndef ARRAY_HPP
# define ARRAY_HPP

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define END	"\033[0m"

# include <iostream>
# include <string>

template<typename T>
class   Array
{
    public:

        Array(void);
        Array(const Array & src);
        Array(unsigned int size);
        ~Array(void);

        Array & operator=(const Array & rhs);

        int     size(void);

    private:

        T*              _array;
        unsigned int    _size;
};

template<typename T>
Array<T>::Array(void) : _size(0)
{
    std::cout
        << YELLOW
        << "Array: Default Constructor Called"
        << END
        << std::endl;
    this->_array = new T[0]();
    return ;
}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
    std::cout
        << YELLOW
        << "Array: Constructor Called"
        << END
        << std::endl;
    this->_array = new T[size]();
}

#endif