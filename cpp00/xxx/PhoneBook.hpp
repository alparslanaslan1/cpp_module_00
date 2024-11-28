#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
private:
    Contact contacts[8];
    int contact_count;

public:
    PhoneBook();  // Constructor
    void add_contact(Contact contact);
    void search_contact();
    static void read_getline(std::string &str);
};

#endif
