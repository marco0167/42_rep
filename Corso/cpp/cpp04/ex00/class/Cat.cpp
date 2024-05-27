#include "./Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &rhs) {
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Miao" << std::endl;
}
