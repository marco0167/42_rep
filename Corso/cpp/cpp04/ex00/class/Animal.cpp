#include "./Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &rhs) {
	*this = rhs;
}

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}
