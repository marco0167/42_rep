#ifndef POINT_HPP
# define POINT_HPP

# include "./Fixed.hpp"

class Point {
	const Fixed	_x;
	const Fixed	_y;

public:

	Point();
	Point(const Fixed a, const Fixed b);
	Point(const Point& obj);
	~Point();

	Point&	operator=(const Point& obj);

    Fixed getX( void ) const ;
    Fixed getY( void ) const ;
};

#endif
