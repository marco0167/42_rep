#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, unsigned int length, void(func)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void print(T &i)
{
	std::cout << i << std::endl;
}

#endif
