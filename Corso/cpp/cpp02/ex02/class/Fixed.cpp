#include "./Fixed.hpp"

Fixed::Fixed() : _fixed_point(0) {}

Fixed::Fixed(const Fixed &f) {
	*this = f;
}

Fixed::Fixed(const int n) : _fixed_point(n << _FRACTIONAL_BITS) {}

Fixed::Fixed(const float n) : _fixed_point((int)roundf(n * (1 << _FRACTIONAL_BITS))) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& obj) {
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

bool	Fixed::operator>(const Fixed& obj) const {
	return this->getRawBits() > obj.getRawBits();
}

bool	Fixed::operator>=(const Fixed& obj) const {
	return this->getRawBits() >= obj.getRawBits();
}

bool	Fixed::operator<(const Fixed& obj) const {
	return this->getRawBits() < obj.getRawBits();
}

bool	Fixed::operator<=(const Fixed& obj) const {
	return this->getRawBits() <= obj.getRawBits();
}

bool	Fixed::operator==(const Fixed& obj) const {
	return this->getRawBits() == obj.getRawBits();
}

bool	Fixed::operator!=(const Fixed& obj) const {
	return this->getRawBits() != obj.getRawBits();
}


Fixed	Fixed::operator+(const Fixed& obj) {
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed	Fixed::operator-(const Fixed& obj) {
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator*(const Fixed& obj) {
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator/(const Fixed& obj) {
	return Fixed(this->toFloat() / obj.toFloat());
}


Fixed&	Fixed::operator++(void) {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed&	Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;

}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;

}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;

}

