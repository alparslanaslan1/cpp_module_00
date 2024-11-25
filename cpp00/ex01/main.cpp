#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <stdexcept>

void read_getline(string &str)
{
	getline(cin, str);
	if (cin.eof())
		throw runtime_error("EOF");
	else if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw runtime_error("Invalid input");
	}
}

void add_contact(PhoneBook &s)
{
	Contact c;
	string str;

	while (1)
	{
		cout << "Enter name: ";
		read_getline(str);
		
	}
}
