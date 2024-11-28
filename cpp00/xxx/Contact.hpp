#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
    std::string name;
    std::string surname;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_nickname() const;
    std::string get_phone_number() const;
    std::string get_darkest_secret() const;

    void set_name(const std::string& name);
    void set_surname(const std::string& surname);
    void set_nickname(const std::string& nickname);
    void set_phone_number(const std::string& phone_number);
    void set_darkest_secret(const std::string& darkest_secret);
    std::string resize_string(const std::string& str) const;
};

#endif
