#include <iostream>

class Contact {
	public:
	std::string	first_name;
	std::string	last_name;
	std::string	phone_number;
	std::string	nickname;
	std::string	drk_secret;
};

class PhoneBook {
	public:
	Contact	contacts[8];
	short	lst_index;
};
