#include "./FragTrap.hpp"

FragTrap::FragTrap(string name) : ClapTrap(name) {
	std::cout << "Constructor for FragTrap " << name << " has benn called!" << std::endl;
	setEnergyPoints(100);
	setHitPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Constructor for FragTrap has benn called!" << std::endl;
	this->_name = "FragTrap";
	setEnergyPoints(100);
	setHitPoints(100);
	setAttackDamage(30);
}


FragTrap::FragTrap(FragTrap &obj) {
	*this = obj;
}

FragTrap&	FragTrap::operator=(const FragTrap &obj) {
	if (this != &obj)
	{
		this->_name = obj._name;
		setAttackDamage(obj._attack_damage);
		setEnergyPoints(obj._energy_points);
		setHitPoints(obj._hit_points);
	}
	return *this;
}

FragTrap::~FragTrap()  {
	std::cout << "Destructor for FragTrap " << getName() << " has been called!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << getName() << " ask for an High Five :)" << std::endl;
}
