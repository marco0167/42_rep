#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(string name) : _name(name) {
	std::cout << "Constructor for ClapTrap " << getName() << " has been called!" << std::endl;
}

ClapTrap::ClapTrap() {
	std::cout << "Constructor for ClapTrap has been called!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &obj) {
	*this = obj;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &obj) {
	if (this != &obj)
	{
		this->_name = obj._name;
		setAttackDamage(obj._attack_damage);
		setEnergyPoints(obj._energy_points);
		setHitPoints(obj._hit_points);
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor for Claptrap " << getName() << " has been called!" << std::endl;
}

void	ClapTrap::attack(const string &target) {
	if (this->_energy_points > 0) {
		setEnergyPoints(this->_energy_points - 1);
		std::cout
			<< "ClapTrap "
			<< getName()
			<< " attacks "
			<< target
			<< ", causing "
			<< getAttackDamage()
			<< " points of damage!"
			<< std::endl;
	} else
		std::cout
			<< "ClapTrap "
			<< getName()
			<< " has not enought EnergyPoint to attack "
			<< target
			<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points > 0) {
		setEnergyPoints(this->_energy_points - 1);
		std::cout
			<< "ClapTrap "
			<< getName()
			<< " has increase his HitPoints by "
			<< amount
			<< "!"
			<< std::endl;
			setHitPoints(this->_hit_points + amount);
		std::cout
			<< "ClapTrap "
			<< getName()
			<< " now has "
			<< this->_hit_points
			<< " HitPoints"
			<< std::endl;
	} else
		std::cout
			<< "ClapTrap "
			<< getName()
			<< " has not enought energy point to increase his HitPoints"
			<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout
		<< "ClapTrap "
		<< getName()
		<< " has been attaked and lose "
		<< amount
		<< " HitPoints!"
		<< std::endl;
	setHitPoints(this->_hit_points - amount);
	if (this->_hit_points <= 0)
		std::cout
			<< "ClapTrap "
			<< getName()
			<< " is DEAD"
			<< std::endl;
	else
		std::cout
			<< "ClapTrap "
			<< getName()
			<< " now has "
			<< this->_hit_points
			<< " HitPoints"
			<< std::endl;
}

void	ClapTrap::setHitPoints(unsigned int amount) {
	this->_hit_points = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount) {
	this->_energy_points = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->_attack_damage = amount;
}

string	ClapTrap::getName() {
	return this->_name;
}

unsigned int	ClapTrap::getAttackDamage() {
	return this->_attack_damage;
}
