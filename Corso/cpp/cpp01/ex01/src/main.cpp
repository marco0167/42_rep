#include "../include/Zombie.h"

int	main(int argc, char **argv)
{
	Zombie	*horde;
	int		horde_size = 10;
	string	zombie_name = "Zombie";

	if (argc != 1 && atoi(argv[1]) > 0)
		horde_size = atoi(argv[1]);
	if (argc > 2 )
		zombie_name = argv[2];

	horde = zombieHorde(horde_size, zombie_name);
	for (int i = 0; i < horde_size; i++)
		horde->announce();

	delete [] horde;
}
