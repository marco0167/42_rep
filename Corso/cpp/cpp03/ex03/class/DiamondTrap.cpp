#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(string name) : ClapTrap( name ), FragTrap( name ), ScavTrap( name ) {
	std::cout << "Constructor for DiamondTrap " << name << " has benn called!" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	ScavTrap::setEnergyPoints(100);
	FragTrap::setHitPoints(50);
	FragTrap::setAttackDamage(30);
}

DiamondTrap::DiamondTrap() : _name("DiamondTrap") {
	std::cout << "Constructor for DiamondTrap has benn called!" << std::endl;
	ScavTrap::setEnergyPoints(100);
	FragTrap::setHitPoints(50);
	FragTrap::setAttackDamage(30);
}


DiamondTrap::DiamondTrap(DiamondTrap &obj) {
	*this = obj;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &obj) {
	if (this != &obj)
	{
		this->_name = obj._name;
		ScavTrap::setAttackDamage(obj._attack_damage);
		ScavTrap::setEnergyPoints(obj._energy_points);
		ScavTrap::setHitPoints(obj._hit_points);
	}
	return *this;
}

DiamondTrap::~DiamondTrap()  {
	std::cout << "Destructor for DiamondTrap " << getName() << " has been called!" << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am a DiamondTrap named " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
