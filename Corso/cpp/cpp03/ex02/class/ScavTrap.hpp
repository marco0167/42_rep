#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define string std::string

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(string name);
	ScavTrap(ScavTrap &obj);
	ScavTrap&	operator=(const ScavTrap& obj);
	~ScavTrap();

	void	attack(const string &target);
	void	guardGate();
};

#endif
