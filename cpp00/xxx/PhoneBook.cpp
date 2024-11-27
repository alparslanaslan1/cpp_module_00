#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

int stringToInt(const string& str)
{
	std::stringstream ss(str);
	int num;

	ss >> num;
	if (ss.fail())
		return 0;
	return num;
}

PhoneBook::PhoneBook() : contact_count(0) {}

void PhoneBook::add_contact(Contact contact)
{
	contacts[contact_count] = contact;
	contact_count++;
	if (contact_count == 8)
		contact_count %= 8;
}

void PhoneBook::search_contact()
{
	int index;
	string tmp;

	cout << "     Index|First name| Last name|  Nickname" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << std::setw(10) << i + 1 << "|";
		cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_name()) << "|";
		cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_surname()) << "|";
		cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_nickname()) << endl;
	}
	cout << "Enter an index: ";
	read_getline(tmp);
	index = stringToInt(tmp);
	if (index < 1 || index > 8)
	{
		cout << "\033[1;31mInvalid index, please enter a valid index.\033[0m" << endl;
		return;
	}
	cout << "First name:     " << contacts[index - 1].get_name() << endl;
	cout << "Last name:      " << contacts[index - 1].get_surname() << endl;
	cout << "Nickname:       " << contacts[index - 1].get_nickname() << endl;
	cout << "Phone number:   " << contacts[index - 1].get_phone_number() << endl;
	cout << "Darkest secret: " << contacts[index - 1].get_darkest_secret() << endl;
}
