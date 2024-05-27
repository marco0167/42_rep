#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class Dog : public Animal {

public:
	Dog();
	~Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);

	void	makeSound() const;
};

#endif
