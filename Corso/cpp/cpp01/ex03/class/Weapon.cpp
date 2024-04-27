#include "./Weapon.hpp"

Weapon::Weapon(string type) : _type(type)
{
	return ;
}

Weapon::Weapon() : _type("Default")
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

string Weapon::getType() const
{
	return this->_type;
}

void	Weapon::setType(string type)
{
	this->_type = type;
}
