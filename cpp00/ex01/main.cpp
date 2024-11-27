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

	while (true)
	{
		cout << "\033[1;32mEnter a first name: \033[0m";
		read_getline(str);
		c.set_name(str);
		cout << "\033[1;32mEnter a last name: \033[0m";
		read_getline(str);
		c.set_surname(str);
		cout << "\033[1;32mEnter a nickname: \033[0m";
		read_getline(str);
		c.set_nickname(str);
		cout << "\033[1;32mEnter a phone number: \033[0m";
		read_getline(str);
		c.set_phone_number(str);
		cout << "\033[1;32mEnter a darkest secret: \033[0m";
		read_getline(str);
		c.set_darkest_secret(str);
		if (c.get_name() == "" || c.get_surname() == "" || c.get_nickname() == ""
			|| c.get_phone_number() == "" || c.get_darkest_secret() == "")
		{
			cout << "\033[1;31mInvalid input, please enter a valid input.\033[0m" << endl;
			continue;
		}
		else
		{
			ref.add_contact(c);
			break;
		}
	}
}

int main()
{
	PhoneBook phone_book;
	string command;
	try
	{
		cout << "\033[2J\033[H" << endl;
		while (true)
		{
			cout << "\033[1;36mEnter a command: \033[0m";

			read_getline(command);
			if (command == "EXIT")
				break;
			else if (command == "ADD")
			{
				add_contact(phone_book);
			}
			else if (command == "SEARCH")
			{
				phone_book.search_contact();
			}
			else
				cout << "\033[1;31mInvalid command, please enter a valid command.\033[0m" << endl;
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



