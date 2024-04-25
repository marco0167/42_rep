#include "../phonebook.h"

class Contact {
	string	first_name;
	string	last_name;
	string	phone_number;
	string	nickname;
	string	drk_secret;

public:

	string	getFirstName(void);
	void	setFirstName(string str);

	string	getLastName(void);
	void	setLastName(string str);

	string	getPhoneNumber(void);
	void	setPhoneNumber(string str);

	string	getNickname(void);
	void	setNickname(string str);

	string	getDkrSecret(void);
	void	setDkrSecret(string str);
};
