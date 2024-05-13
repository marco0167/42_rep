#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	int					_fixed_point;
	static const int	_FRACTIONAL_BITS = 8;

public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();
	Fixed&	operator=(const Fixed& obj);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool	operator>(const Fixed& obj) const;
	bool	operator>=(const Fixed& obj) const;
	bool	operator<(const Fixed& obj) const;
	bool	operator<=(const Fixed& obj) const;
	bool	operator==(const Fixed& obj) const;
	bool	operator!=(const Fixed& obj) const;

	Fixed	operator+(const Fixed& obj);
	Fixed	operator-(const Fixed& obj);
	Fixed	operator*(const Fixed& obj);
	Fixed	operator/(const Fixed& obj);

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed& min( Fixed &a, Fixed &b );
    static const Fixed& min( const Fixed &a, const Fixed &b );
    static Fixed& max( Fixed &a, Fixed &b );
    static const Fixed& max( const Fixed &a, const Fixed &b );

};

std::ostream & operator<<( std::ostream & o, const Fixed& i );

#endif
