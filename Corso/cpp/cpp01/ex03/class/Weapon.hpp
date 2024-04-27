#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

# define string std::string

class Weapon {
	string	_type;

	public:
	Weapon(string type);
	Weapon();
	~Weapon();

	string	getType() const;
	void	setType(string type);

};

#endif
