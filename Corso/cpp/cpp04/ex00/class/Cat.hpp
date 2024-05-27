#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

public:
	Cat();
	~Cat();
	Cat(const Cat &rhs);
	Cat &operator=(const Cat &rhs);

	void	makeSound() const;
};

#endif
