#include "./Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "DEBUG MESSAGE" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO MESSAGE" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING MESSAGE" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR MESSAGE" << std::endl;
}

void Harl::complain(string level) {
	std::map<string, void(Harl::*)(void)> prints;

	prints["DEBUG"] = &Harl::debug;
	prints["INFO"] = &Harl::info;
	prints["WARNING"] = &Harl::warning;
	prints["ERROR"] = &Harl::error;

	(this->*prints[level])();
}
