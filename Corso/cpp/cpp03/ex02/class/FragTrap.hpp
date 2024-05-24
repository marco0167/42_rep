#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define string std::string

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(string name);
	FragTrap(FragTrap &obj);
	FragTrap&	operator=(const FragTrap& obj);
	~FragTrap();

	void	highFivesGuys();
};

#endif
