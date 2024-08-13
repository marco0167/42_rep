#include "../class/Serializer.hpp"

int	main()
{
	Data *d1 = new Data();
    uintptr_t ptr = Serializer::serialize(d1);
    Data *d2 = Serializer::deserialize(ptr);

    std::cout << "Data 1: " << d1 << std::endl;
    std::cout << "Data 2: " << d2 << std::endl;
    delete d1;
	return (0);
}
