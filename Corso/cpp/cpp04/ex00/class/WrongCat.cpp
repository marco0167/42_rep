#include "./WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs) {
	*this = rhs;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs) {

	}
	return *this;
}
