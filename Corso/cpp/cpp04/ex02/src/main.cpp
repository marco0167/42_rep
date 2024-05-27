#include "../class/Animal.hpp"
#include "../class/Dog.hpp"
#include "../class/Cat.hpp"


int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;


	return 0;
}

