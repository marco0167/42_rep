#include "./phonebook.hpp"

void	addContact(PhoneBook *phonebook)
{
	Contact	new_contact;

	getline(std::cin, new_contact.first_name);
	std::cout << "\nInsert the new contact name: ";
	getline(std::cin, new_contact.first_name);
	std::cout << "Insert the new contact last name: ";
	getline(std::cin, new_contact.last_name);
	std::cout << "Insert the new contact phone number: ";
	getline(std::cin, new_contact.phone_number);
	std::cout << "Insert the new contact nickname: ";
	getline(std::cin, new_contact.nickname);
	std::cout << "Insert the new contact darkest secret: ";
	getline(std::cin, new_contact.drk_secret);
	if (!new_contact.first_name[0] || !new_contact.last_name[0]
		|| !new_contact.phone_number[0] || !new_contact.nickname[0]
		|| !new_contact.drk_secret[0])
		{
			std::cout << "\nContact not saved (found empty field)\n\n";
			return ;
		}
	if (phonebook->lst_index == 7)
	{
		phonebook->lst_index = 0;
		phonebook->contacts[phonebook->lst_index] = new_contact;
	}
	else
		phonebook->contacts[++phonebook->lst_index] = new_contact;
}

void	printCol(std::string str)
{
	int	len = str.length();
	int	index = 0;

	for (int i = 0; i < 10; i++)
	{
		if (len > 10 && i == 9)
				std::cout << '.';
		else if (len + i < 10)
				std::cout << ' ';
		else
			std::cout << str[index++];
	}
}

void	searchContact(PhoneBook *phonebook)
{
	std::string id;

	std::cout << "\nSelect one contact by typing the ID: ";
	std::cin >> id;

	if ((id[0] - 48) < 8 && phonebook->contacts[(id[0] - 48)].first_name[0])
	{
		std::cout << phonebook->contacts[(id[0] - 48)].first_name << '\n';
		std::cout << phonebook->contacts[(id[0] - 48)].last_name << '\n';
		std::cout << phonebook->contacts[(id[0] - 48)].phone_number << '\n';
		std::cout << phonebook->contacts[(id[0] - 48)].nickname << '\n';
		std::cout << phonebook->contacts[(id[0] - 48)].drk_secret << "\n\n";
	}
	else
		std::cout << "\nNo contact found with this ID\n\n";
}

void	printHeader()
{
	printCol("    ID    ");
	std::cout << '|';
	printCol("FIRST NAME");
	std::cout << '|';
	printCol("LAST  NAME");
	std::cout << '|';
	printCol(" NICKNAME ");
	std::cout << '\n';
}

void	printContact(PhoneBook *phonebook)
{
	int	c = 0;

	std::cout << '\n';
	for (int i = 0; i < 8; i++)
	{
		if (!phonebook->contacts[i].first_name[0])
		continue ;
		if (i == 0)
			printHeader();
		printCol(std::to_string(i));
		std::cout << '|';
		printCol(phonebook->contacts[i].first_name);
		std::cout << '|';
		printCol(phonebook->contacts[i].last_name);
		std::cout << '|';
		printCol(phonebook->contacts[i].nickname);
		std::cout << '\n';
		c++;
	}
	if (!c)
		std::cout << "\n\n\t\tNO CONTACT SAVED\n\n\n";
	else
		searchContact(phonebook);
}



int main()
{
	std::string action;
	PhoneBook PhoneBook;

	PhoneBook.lst_index = -1;
	while (1)
	{
		std::cout << "\nEnter one of this command: ADD | SEARCH | EXIT\n";
		std::cin >> action;
		if (action.compare("ADD") == 0)
			addContact(&PhoneBook);
		else if (action.compare("SEARCH") == 0)
			printContact(&PhoneBook);
		else if (action.compare("EXIT") == 0)
			break ;
	}
	return 0;
}
