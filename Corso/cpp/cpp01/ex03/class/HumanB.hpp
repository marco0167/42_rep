#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "./Weapon.hpp"

class HumanB {
	string	_name;
	Weapon	*_weapon;

public:
	HumanB(string name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack() const;
};

#endif
