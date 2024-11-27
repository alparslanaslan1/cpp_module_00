#include "Contact.hpp"

string Contact::get_name()
{
	return (name);
}

string Contact::get_surname()
{
	return(surname);
}

string Contact::get_nickname()
{
	return(nickname);
}

string Contact::get_phone_number()
{
	return(phone_number);
}


string Contact::get_darkest_secret()
{
	return(darkest_secret);
}

void Contact::set_name(string name)
{
	this->name = name;
}

void Contact::set_surname(string surname)
{
	this->surname = surname;
}

void Contact::set_nickname(string nickname)
{
	this->nickname = nickname;
}

void Contact::set_phone_number(string phone_number)
{
	this->phone_number = phone_number;
}

void Contact::set_darkest_secret(string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

string Contact::resize_string(string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	return str;
}
