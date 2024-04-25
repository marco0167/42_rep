#include "../phonebook.h"

class Contact {
	public:
	std::string	first_name;
	std::string	last_name;
	std::string	phone_number;
	std::string	nickname;
	std::string	drk_secret;

	void	setFirstName(std::string str)
	{
		first_name = str;
	}
	std::string	getFirstName()
	{
		return first_name;
	}
};
