#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data
{
	std::string s1;
	int i;
};

class Serializer
{
	Serializer();

public:
	~Serializer();
	Serializer(const Serializer &rhs);
	Serializer &operator=(const Serializer &rhs);

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
