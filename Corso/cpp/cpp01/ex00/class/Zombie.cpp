#include "../include/Zombie.h"

Zombie::Zombie(string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << "\n";
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
