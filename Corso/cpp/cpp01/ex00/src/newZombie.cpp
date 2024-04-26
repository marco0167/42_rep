#include "../include/Zombie.h"

Zombie* newZombie( string name )
{
	Zombie *zombie = new Zombie(name);

	return zombie;
}
