#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	int					fixedPoint;
	static const int	FRACTIONAL_BITS = 8;

public:
	Fixed();
	Fixed(const Fixed &f);
	~Fixed();
	Fixed& operator=(const Fixed& obj);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
