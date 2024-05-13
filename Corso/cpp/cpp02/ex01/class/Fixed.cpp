#include "./Fixed.hpp"


Fixed::Fixed() : _fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int n) : _fixed_point(n << _FRACTIONAL_BITS) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixed_point((int)roundf(n * (1 << _FRACTIONAL_BITS))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_fixed_point = obj.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits() const {
	return this->_fixed_point;
}

void	Fixed::setRawBits(int const raw) {
	_fixed_point = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>(this->getRawBits()) / (1 << _FRACTIONAL_BITS);
}

int	Fixed::toInt( void ) const {
	return this->getRawBits() >> _FRACTIONAL_BITS;
}

std::ostream& operator<<( std::ostream& o, const Fixed& i ) {
	o << i.toFloat();
	return o;
}
