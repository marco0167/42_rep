#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(string name) : _name(name) {
	std::cout << "Constructor for Claptrap " << this->_name << "has been called!" << std::endl;
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
	std::cout << "Destructor for Claptrap " << this->_name << "has been called!" << std::endl;
}

void	ClapTrap::attack(const string &target) {
	if (this->_energy_points > 0) {
		setEnergyPoints(this->_energy_points - 1);
		std::cout
			<< "ClapTrap "
			<< this->_name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attack_damage
			<< " points of damage!"
			<< std::endl;
	} else
		std::cout
			<< "ClapTrap "
			<< this->_name
			<< " has not enought EnergyPoint to attack "
			<< target
			<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points > 0) {
		setEnergyPoints(this->_energy_points - 1);
		std::cout
			<< "ClapTrap "
			<< this->_name
			<< " has increase his HitPoints from "
			<< this->_hit_points
			<< " to "
			<< this->_hit_points + amount
			<< std::endl;
			setHitPoints(this->_hit_points + amount);
	} else
		std::cout
			<< "ClapTrap "
			<< this->_name
			<< " has not enought energy point to increase his HitPoints"
			<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout
		<< "ClapTrap "
		<< this->_name
		<< " has been attaked and lose "
		<< amount
		<< " HitPoints "
		<< std::endl;
	setHitPoints(this->_hit_points - amount);
	if (this->_hit_points <= 0)
		std::cout
			<< "ClapTrap "
			<< this->_name
			<< " is DEAD"
			<< std::endl;
	else
		std::cout
			<< " Now it has "
			<< this->_hit_points
			<< " HitPoints"
			<< std::endl;
}

void	ClapTrap::setHitPoints(unsigned int amount) {
	this->_hit_points = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount) {
	this->_hit_points = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->_hit_points = amount;
}
