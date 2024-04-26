#include "../include/Zombie.h"

Zombie::Zombie(string name) : _name(name)
{
	return ;
}
Zombie::Zombie(void) : _name("Zombie")
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << _name << " dead" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(string name)
{
	_name = name;
}
