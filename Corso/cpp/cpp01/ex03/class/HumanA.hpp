#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "./Weapon.hpp"


class HumanA {
	string	_name;
	Weapon	&_weapon;

public:
	HumanA(string name, Weapon &weapon);
	~HumanA();
	void	attack() const;
};


#endif
