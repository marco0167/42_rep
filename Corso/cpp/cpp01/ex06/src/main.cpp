#include "../class/Harl.hpp"

int main(int argc, char **argv) {
	Harl	harl;
	string	key[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	short	val = -1;

	if (argc != 2)
		return (std::cout << ARGUMENTS, 1);

	for (int i = 0; i < 4; i++) {
		if (argv[1] == key[i])
			val = i;
	}

	switch (val) {
		case 0:
			harl.debug();
		case 1:
			harl.info();
		case 2:
			harl.warning();
		case 3:
			harl.error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

	return 0;
}
