#include "PhoneBook.hpp"
#include "Contact.hpp"

void add_contact(PhoneBook &phone_book)
{
    Contact contact;
    std::string input;

    while (true)
	{
        std::cout << "Enter first name: ";
        PhoneBook::read_getline(input);
        contact.set_name(input);

        std::cout << "Enter last name: ";
        PhoneBook::read_getline(input);
        contact.set_surname(input);

        std::cout << "Enter nickname: ";
        PhoneBook::read_getline(input);
        contact.set_nickname(input);

        std::cout << "Enter phone number: ";
        PhoneBook::read_getline(input);
        contact.set_phone_number(input);

        std::cout << "Enter darkest secret: ";
        PhoneBook::read_getline(input);
        contact.set_darkest_secret(input);

        if (contact.get_name().empty() || contact.get_surname().empty() ||
            contact.get_nickname().empty() || contact.get_phone_number().empty() ||
            contact.get_darkest_secret().empty())
		{
            std::cout << "\033[1;31mInvalid input, please enter a valid input.\033[0m" << std::endl;
            continue;
        }
		else
		{
            phone_book.add_contact(contact);
            break;
        }
    }
}

int main()
{
    PhoneBook phone_book;
    std::string input;

    try
    {
        while (true)
    	{
            std::cout << "\033[1;36mEnter a command (ADD, SEARCH, EXIT): \033[0m";
            PhoneBook::read_getline(input);

            if (input == "EXIT")
    		{
                std::cout << "Exiting program..." << std::endl;
                break;
            }
    		else if (input == "ADD")
    		{
                add_contact(phone_book);
            }
    		else if (input == "SEARCH")
    		{
                phone_book.search_contact();
            }
    		else
    		{
                std::cout << "\033[1;31mInvalid command, please enter a valid command.\033[0m" << std::endl;
            }
        }
    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(...)
	{
		std::cerr << "Unknown exception" << '\n';
	}
}
