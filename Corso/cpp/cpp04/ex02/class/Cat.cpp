#include "./Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &rhs) {
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain( *rhs._brain );
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Miao" << std::endl;
}
