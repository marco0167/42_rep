#include "./Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed a, const Fixed b) : _x(a), _y(b) {}

Point::Point(const Point& obj) {
	*this = obj;
}

Point& Point::operator=(const Point& obj) {
	if (this != &obj)
	{
		(Fixed) this->_x = obj.getX();
		(Fixed) this->_y = obj.getY();
	}
}


Fixed	Point::getX( void ) const {
	return this->_x;
}

Fixed	Point::getY( void ) const {
	return this->_y;
}
