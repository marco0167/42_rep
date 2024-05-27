#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	std::string ideas[100];

public:
	Brain();
	~Brain();
	Brain(const Brain &rhs);
	Brain &operator=(const Brain &rhs);
};

#endif
