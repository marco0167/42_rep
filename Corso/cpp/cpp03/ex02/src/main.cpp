#include "../class/FragTrap.hpp"


int	main()
{
	FragTrap user1;
	FragTrap user2("Matteo");

	user1.highFivesGuys();
	user2.highFivesGuys();
	user1.setEnergyPoints(1);
	user1.setAttackDamage(1);
	user2.setAttackDamage(10);
	user1.attack(user2.getName());
	user2.takeDamage(user1.getAttackDamage());
	user1.attack(user2.getName());
	user2.beRepaired(10);
	user2.attack(user1.getName());
	user1.takeDamage(user2.getAttackDamage());


	return 0;
}

