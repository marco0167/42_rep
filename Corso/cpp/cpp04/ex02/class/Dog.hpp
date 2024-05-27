#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	Brain* _brain;

public:
	Dog();
	~Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);

	void	makeSound() const;
};

#endif
