#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# define string std::string

class DiamondTrap : public FragTrap, public ScavTrap {
	string	_name;
public:
	DiamondTrap();
	DiamondTrap(string name);
	DiamondTrap(DiamondTrap &obj);
	DiamondTrap&	operator=(const DiamondTrap& obj);
	~DiamondTrap();

	using	ScavTrap::attack;
	void	whoAmI();
};

#endif
