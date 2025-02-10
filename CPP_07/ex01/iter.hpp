#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>
void    iter(T* array, int size, void func(T &))
{
    for (int i = 0; i < size; i++)
        func(array[i]);
    return ;
}

template<typename T>
void    up(T & a)
{
    a *= 10;
    return ;
}

template<typename T>
void    rename(T & name)
{
    name = "Glam";
    return ;
}

#endif