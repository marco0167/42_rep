#include "../include/Zombie.h"

int	main()
{
	Zombie zombieistance("Antonio");
	Zombie *zombie2 = newZombie("Andrea");

	zombie2->announce();
	randomChump("ettore");
	zombieistance.announce();
	
	delete zombie2;

	return 0;
}
