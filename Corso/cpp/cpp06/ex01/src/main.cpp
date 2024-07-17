#include "../class/Serializer.hpp"

int	main()
{
	Data *d1 = new Data();
    uintptr_t ptr = serialize(d1);
    Data *d2 = deserialize(ptr);

    std::cout << "Data 1: " << d1 << std::endl;
    std::cout << "Data 2: " << d2 << std::endl;
	return (0);
}
