#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define string std::string

class ClapTrap {

	string			_name;
	unsigned int	_hit_points = 10;
	unsigned int	_energy_points = 10;
	unsigned int	_attack_damage = 0;

public:
	ClapTrap(string name);
	ClapTrap(ClapTrap &obj);
	ClapTrap&	operator=(const ClapTrap& obj);
	~ClapTrap();

	void			attack(const string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
		
	void			setHitPoints(unsigned int amount);
	void			setEnergyPoints(unsigned int amount);
	void			setAttackDamage(unsigned int amount);
		
	string			getName();
	unsigned int	getAttackDamage();

};



#endif
