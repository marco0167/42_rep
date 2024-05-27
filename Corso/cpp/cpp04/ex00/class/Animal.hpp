#ifndef Animal_HPP
# define Animal_HPP

#include <iostream>

class Animal {
protected:
	std::string _type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &rhs);
	Animal &operator=(const Animal &rhs);

	virtual void	makeSound() const;

	std::string getType() const;
};

#endif
