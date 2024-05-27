#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	Brain* _brain;

public:
	Cat();
	~Cat();
	Cat(const Cat &rhs);
	Cat &operator=(const Cat &rhs);

	void	makeSound() const;
};

#endif
