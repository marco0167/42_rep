#include "../class/Animal.hpp"
#include "../class/Dog.hpp"
#include "../class/Cat.hpp"


int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!


	return 0;
}

