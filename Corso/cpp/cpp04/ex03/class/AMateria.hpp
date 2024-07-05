#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

# define string std::string

class AMateria {
protected:
	string	_type;

public:
	AMateria(string const & type);
	AMateria();
	~AMateria();
	AMateria(const AMateria &rhs);
	AMateria &operator=(const AMateria &rhs);

	string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	// virtual void use(ICharacter& target);
};


#endif
