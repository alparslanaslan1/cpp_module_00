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
	string get_name();
	string get_surname();
	string get_nickname();
	string get_phone_number();
	string get_darkest_secret();
	void set_name(string name);
	void set_surmname(string surname);
	void set_nickname(string nickname);
	void set_phone_number(string phone_number);
	void set_darkest_secret(string darkest_secret);
};

#endif
