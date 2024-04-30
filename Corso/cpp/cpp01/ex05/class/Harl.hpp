#ifndef HARL_HPP
# define HARL_HPP

# include "../includes/Harl.h"

class Harl {
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	Harl();
	~Harl();
	void complain( string level );
};

#endif
