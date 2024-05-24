#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
	std::cout << "Constructor for ScavTrap " << name << " has benn called!" << std::endl;
	setEnergyPoints(50);
	setHitPoints(100);
	setAttackDamage(20);
}

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Constructor for ScavTrap has benn called!" << std::endl;
	this->_name = "ScavTrap";
	setEnergyPoints(50);
	setHitPoints(100);
	setAttackDamage(20);
}


ScavTrap::ScavTrap(ScavTrap &obj) {
	*this = obj;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &obj) {
	if (this != &obj)
	{
		this->_name = obj._name;
		setAttackDamage(obj._attack_damage);
		setEnergyPoints(obj._energy_points);
		setHitPoints(obj._hit_points);
	}
	return *this;
}

ScavTrap::~ScavTrap()  {
	std::cout << "Destructor for ScavTrap " << getName() << " has been called!" << std::endl;
}

void	ScavTrap::attack(const string &target) {
	if (this->_energy_points > 0) {
		setEnergyPoints(this->_energy_points - 1);
		std::cout
			<< "ScavTrap"
			<< getName()
			<< " attacks "
			<< target
			<< ", causing "
			<< getAttackDamage()
			<< " points of damage!"
			<< std::endl;
	} else
		std::cout
			<< "ScavTrap"
			<< getName()
			<< " has not enought EnergyPoint to attack "
			<< target
			<< std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}
