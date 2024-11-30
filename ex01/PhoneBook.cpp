#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook() : contact_count(0) {}

void PhoneBook::read_getline(std::string &str)
{
    std::getline(std::cin, str);

    if (std::cin.eof())
    {

        throw std::runtime_error("EOF encountered");
    }
    else if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Invalid input");
    }
}


void PhoneBook::add_contact(Contact contact)
{
    contacts[contact_count] = contact;
    contact_count++;

    if (contact_count == 8)
    {
        contact_count = 0;
    }
}

void PhoneBook::search_contact()
{
    int index;
    std::string tmp;

    std::cout << "     Index|First name| Last name|  Nickname" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_name()) << "|";
        std::cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_surname()) << "|";
        std::cout << std::setw(10) << contacts[i].resize_string(contacts[i].get_nickname()) << std::endl;
    }

    std::cout << "Enter an index: ";
    read_getline(tmp);
    index = std::atoi(tmp.c_str());

    if (index < 1 || index > 8)
    {
        std::cout << "\033[1;31mInvalid index, please enter a valid index.\033[0m" << std::endl;
        return;
    }

    std::cout << "First name:     " << contacts[index - 1].get_name() << std::endl;
    std::cout << "Last name:      " << contacts[index - 1].get_surname() << std::endl;
    std::cout << "Nickname:       " << contacts[index - 1].get_nickname() << std::endl;
    std::cout << "Phone number:   " << contacts[index - 1].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contacts[index - 1].get_darkest_secret() << std::endl;
}
