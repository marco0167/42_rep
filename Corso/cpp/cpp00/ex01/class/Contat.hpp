#include "../phonebook.h"


class Contact {
	string	first_name;
	string	last_name;
	string	phone_number;
	string	nickname;
	string	drk_secret;

	public:

	Contact(string first_name, string last_name, string phone_number, string nickname, string drk_secret)
	{
		this->first_name = first_name;
		this->last_name = last_name;
		this->phone_number = phone_number;
		this->nickname = nickname;
		this->drk_secret = drk_secret;
	}

	Contact(){};
	~Contact(){};

	string	getFirstName()
	{
		return first_name;
	}

	string	getLastName()
	{
		return first_name;
	}

	string	getPhoneNumber()
	{
		return first_name;
	}

	string	getNickname()
	{
		return first_name;
	}

	string	getDkrSecret()
	{
		return first_name;
	}
};
