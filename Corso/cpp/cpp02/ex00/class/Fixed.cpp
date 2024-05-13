#include "./Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->fixedPoint = obj.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void	Fixed::setRawBits(int const raw) {
	fixedPoint = raw;
}
