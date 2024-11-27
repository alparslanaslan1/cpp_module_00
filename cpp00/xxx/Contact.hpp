#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::getline;

class Contact
{
	private:
	string name;
	string surname;
	string nickname;
	string phone_number;
	string darkest_secret;

	public:
	string Contact::get_name();
	string Contact::get_surname();
	string Contact::get_nickname();
	string Contact::get_phone_number();
	string Contact::get_darkest_secret();

	void set_name(string name);
	void set_surname(string surname);
	void set_nickname(string nickname);
	void set_phone_number(string phone_number);
	void set_darkest_secret(string darkest_secret);
	string Contact::resize_string(string str);

};

#endif
