#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "../include/Zombie.h"

class Zombie {
	string	name;

public:

	Zombie(string name);
	~Zombie();

	void announce( void );

};

#endif
