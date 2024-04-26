#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "../include/Zombie.h"

class Zombie {
	string	_name;

public:

	Zombie(string name);
	Zombie();
	~Zombie();

	void	setName(string name);
	void	announce( void );

};

#endif
