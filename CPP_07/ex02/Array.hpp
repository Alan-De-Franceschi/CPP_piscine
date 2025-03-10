#ifndef ARRAY_HPP
# define ARRAY_HPP

# define GREEN 	"\033[0;32m"
# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define END	"\033[0m"

# include <iostream>
# include <string>
# include <exception>
# include <iomanip>

template<typename T>
class   Array
{
    public:

        Array(void);
        Array(const Array & src);
        Array(int size);
        ~Array(void);

        Array &                 operator=(const Array & rhs);
        T &                     operator[](int i);
        const T &               operator[](int i) const;

        int                     size(void) const;

    private:

        T*                      _array;
        int                     _size;
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
Array<T>::Array(int size) : _size(size)
{
    std::cout
        << YELLOW
        << "Array: Constructor Called"
        << END
        << std::endl;
    if (this->_size < 0)
        throw std::invalid_argument("Error: Array size can't be negative");
    this->_array = new T[size]();
}

template<typename T>
Array<T>::Array(const Array & src)
{
    std::cout
        << YELLOW
        << "Array: Copy Constructor Called"
        << END
        << std::endl;
    this->_array = new T[0]();
    *this = src;
    return ;
}

template<typename T>
Array<T>::~Array(void)
{
    std::cout
        << YELLOW
        << "Array: Destructor Called"
        << END
        << std::endl;
    delete [] this->_array;
    return ;
}

template<typename T>
Array<T> & Array<T>::operator=(const Array & rhs)
{
    this->_size = rhs._size;
    delete [] this->_array;
    this->_array = new T[rhs._size]();
    for (int i = 0; i < this->_size; i++)
        this->_array[i] = rhs._array[i];
    return (*this);
}

template<typename T>
T & Array<T>::operator[](int i)
{
    if (i >= this->_size || i < 0)
        throw std::out_of_range("Operator[]: Index is out of bounds");
    return (this->_array[i]);
}

template<typename T>
const T & Array<T>::operator[](int i) const
{
    if (i >= this->_size || i < 0)
        throw std::out_of_range("Operator[]: Index is out of bounds");
    return (this->_array[i]);
}

template<typename T>
int    Array<T>::size(void) const
{
    return (this->_size);
}

#endif