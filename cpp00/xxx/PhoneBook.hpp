#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"



void read_getline(string &str);

class PhoneBook
{
private:
	Contact contacts[8];
	int contact_count;
public:
	PhoneBook();
	void read_getline(string &str);
	void PhoneBook::search_contact();
	void PhoneBook::add_contact(Contact contact);

};

#endif
