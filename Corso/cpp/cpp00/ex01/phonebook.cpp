#include "./phonebook.h"

void	addContact(PhoneBook *phonebook)
{
	string	first_name;
	string	last_name;
	string	phone_number;
	string	nickname;
	string	drk_secret;

	system("clear");
	getline(cin, first_name);
	cout << "\nInsert the new contact name: ";
	getline(cin, first_name);
	cout << "Insert the new contact last name: ";
	getline(cin, last_name);
	cout << "Insert the new contact phone number: ";
	getline(cin, phone_number);
	cout << "Insert the new contact nickname: ";
	getline(cin, nickname);
	cout << "Insert the new contact darkest secret: ";
	getline(cin, drk_secret);
	if (!first_name[0] || !last_name[0] || !phone_number[0] || !nickname[0]
		|| !drk_secret[0])
		{
			cout << "\nContact not saved (found empty field)\n\n";
			return ;
		}
	Contact new_contact(first_name, last_name, phone_number, nickname, drk_secret);
	if (phonebook->lst_index == 7)
	{
		phonebook->lst_index = 0;
		phonebook->contacts[phonebook->lst_index] = new_contact;
	}
	else
		phonebook->contacts[++phonebook->lst_index] = new_contact;
}

string index_to_string(short i)
{
	string str;

	str.append(1, (char)(i + 48));
	return str;
}

void	printCol(string str, char extra_char)
{
	int	len = str.length();

	cout << std::setw(10);
	if (len > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	cout << str << extra_char;
}

void	searchContact(PhoneBook *phonebook)
{
	string id;

	cout << "\nSelect one contact by typing the ID: ";
	cin >> id;
	system("clear");
	if (id[0] >= 48 && (id[0] - 48) < 8 && phonebook->contacts[(id[0] - 48)].getFirstName()[0])
	{
		cout << "\nCONTACT INFO\n\n";
		cout << "First Name:     ";
		cout << phonebook->contacts[(id[0] - 48)].getFirstName() << '\n';
		cout << "Last Name:      ";
		cout << phonebook->contacts[(id[0] - 48)].getLastName() << '\n';
		cout << "Phone Number:   ";
		cout << phonebook->contacts[(id[0] - 48)].getPhoneNumber() << '\n';
		cout << "Nickname:       ";
		cout << phonebook->contacts[(id[0] - 48)].getNickname() << '\n';
		cout << "Darkest Secret: ";
		cout << phonebook->contacts[(id[0] - 48)].getDkrSecret() << "\n\n";
	}
	else
		cout << "\nNo contact found with this ID\n\n";
}

void	printHeader()
{
	printCol("    ID    ", '|');
	printCol("FIRST NAME", '|');
	printCol("LAST  NAME", '|');
	printCol(" NICKNAME ", '\n');
}

void	printContact(PhoneBook *phonebook)
{
	int	c = 0;

	system("clear");
	for (int i = 0; i < 8; i++)
	{
		if (!phonebook->contacts[i].getFirstName()[0])
		continue ;
		if (i == 0)
			printHeader();
		printCol(index_to_string(i), '|');
		printCol(phonebook->contacts[i].getFirstName(), '|');
		printCol(phonebook->contacts[i].getLastName(), '|');
		printCol(phonebook->contacts[i].getNickname(), '\n');
		c++;
	}
	if (!c)
		cout << "\n\n\t\tNO CONTACT SAVED\n\n\n";
	else
		searchContact(phonebook);
}

int main()
{
	string action;
	PhoneBook PhoneBook;

	PhoneBook.lst_index = -1;
	while (1)
	{
		cout << "\nEnter one of this command: ADD | SEARCH | EXIT\n";
		cin >> action;
		if (action.compare("ADD") == 0)
			addContact(&PhoneBook);
		else if (action.compare("SEARCH") == 0)
			printContact(&PhoneBook);
		else if (action.compare("EXIT") == 0)
			break ;
	}
	return 0;
}
