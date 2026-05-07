
#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename F>
void iter(T *arrayAddress, const int arrayLength, F func) 
{
    for (int i = 0; i < arrayLength; i++)
        func(arrayAddress[i]);
}
/*
template <typename T>
void iter(T *array, int length, void (*func)(T&))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void iter(const T *array, int length, void (*func)(const T&))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

#endif
*/
#endif