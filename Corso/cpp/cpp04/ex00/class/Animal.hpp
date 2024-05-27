#ifndef Animal_HPP
# define Animal_HPP

#include <iostream>

class Animal {
protected:
	std::string _type;

public:
	Animal();
	~Animal();
	Animal(const Animal &rhs);
	Animal &operator=(const Animal &rhs);

	void	makeSound() const;
};

#endif
