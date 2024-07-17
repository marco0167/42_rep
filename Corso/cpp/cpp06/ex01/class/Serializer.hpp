#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data
{
	std::string s1;
	int i;
};

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);

#endif
