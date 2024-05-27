#include "./Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) {
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Bau" << std::endl;
}
