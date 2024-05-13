#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath>

class Fixed {
	int					_fixed_point;
	static const int	_FRACTIONAL_BITS = 8;

public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();
	Fixed& operator=(const Fixed& obj);
	Fixed& operator<<(float n);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, const Fixed& i );

#endif
